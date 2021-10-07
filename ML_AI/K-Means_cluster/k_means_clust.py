import warnings

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.metrics import pairwise_distances

warnings.filterwarnings("ignore")

TAG = "K-MEANS-CLUST/ "


def get_initial_centroids(data, k, seed=None):
    if seed is not None:  # useful for obtaining consistent results
        np.random.seed(seed)
    n = data.shape[0]  # number of data points

    # Pick K indices from range [0, N).
    rand_indices = np.random.randint(0, n, k)

    # Keep centroids as dense format, as many entries will be nonzero due to averaging.
    # As long as at least one document in a cluster contains a word,
    # it will carry a nonzero weight in the TF-IDF vector of the centroid.
    centroids = data[rand_indices, :]

    return centroids


def centroid_pairwise_dist(X, centroids):
    return pairwise_distances(X, centroids, metric="euclidean")


def assign_clusters(data, centroids):

    # Compute distances between each data point and the set of centroids:
    # Fill in the blank (RHS only)
    distances_from_centroids = centroid_pairwise_dist(data, centroids)

    # Compute cluster assignments for each data point:
    # Fill in the blank (RHS only)
    cluster_assignment = np.argmin(distances_from_centroids, axis=1)

    return cluster_assignment


def revise_centroids(data, k, cluster_assignment):
    new_centroids = []
    for i in range(k):
        # Select all data points that belong to cluster i. Fill in the blank (RHS only)
        member_data_points = data[cluster_assignment == i]
        # Compute the mean of the data points. Fill in the blank (RHS only)
        centroid = member_data_points.mean(axis=0)
        new_centroids.append(centroid)
    new_centroids = np.array(new_centroids)

    return new_centroids


def compute_heterogeneity(data, k, centroids, cluster_assignment):

    heterogeneity = 0.0
    for i in range(k):

        # Select all data points that belong to cluster i. Fill in the blank (RHS only)
        member_data_points = data[cluster_assignment == i, :]

        if member_data_points.shape[0] > 0:  # check if i-th cluster is non-empty
            # Compute distances from centroid to data points (RHS only)
            distances = pairwise_distances(
                member_data_points, [centroids[i]], metric="euclidean"
            )
            squared_distances = distances ** 2
            heterogeneity += np.sum(squared_distances)

    return heterogeneity


def plot_heterogeneity(heterogeneity, k):
    plt.figure(figsize=(7, 4))
    plt.plot(heterogeneity, linewidth=4)
    plt.xlabel("# Iterations")
    plt.ylabel("Heterogeneity")
    plt.title(f"Heterogeneity of clustering over time, K={k:d}")
    plt.rcParams.update({"font.size": 16})
    plt.show()


def kmeans(
    data, k, initial_centroids, maxiter=500, record_heterogeneity=None, verbose=False
):

    centroids = initial_centroids[:]
    prev_cluster_assignment = None

    for itr in range(maxiter):
        if verbose:
            print(itr, end="")

        # 1. Make cluster assignments using nearest centroids
        cluster_assignment = assign_clusters(data, centroids)

        # 2. Compute a new centroid for each of the k clusters, averaging all data
        #    points assigned to that cluster.
        centroids = revise_centroids(data, k, cluster_assignment)

        # Check for convergence: if none of the assignments changed, stop
        if (
            prev_cluster_assignment is not None
            and (prev_cluster_assignment == cluster_assignment).all()
        ):
            break

        # Print number of new assignments
        if prev_cluster_assignment is not None:
            num_changed = np.sum(prev_cluster_assignment != cluster_assignment)
            if verbose:
                print(
                    "    {:5d} elements changed their cluster assignment.".format(
                        num_changed
                    )
                )

        # Record heterogeneity convergence metric
        if record_heterogeneity is not None:
            # YOUR CODE HERE
            score = compute_heterogeneity(data, k, centroids, cluster_assignment)
            record_heterogeneity.append(score)

        prev_cluster_assignment = cluster_assignment[:]

    return centroids, cluster_assignment

def ReportGenerator(
    df: pd.DataFrame, ClusteringVariables: np.array, FillMissingReport=None
) -> pd.DataFrame:

    # Fill missing values with given rules
    if FillMissingReport:
        df.fillna(value=FillMissingReport, inplace=True)
    df["dummy"] = 1
    numeric_cols = df.select_dtypes(np.number).columns
    report = (
        df.groupby(["Cluster"])[  # construct report dataframe
            numeric_cols
        ]  # group by cluster number
        .agg(
            [
                ("sum", np.sum),
                ("mean_with_zeros", lambda x: np.mean(np.nan_to_num(x))),
                ("mean_without_zeros", lambda x: x.replace(0, np.NaN).mean()),
                (
                    "mean_25-75",
                    lambda x: np.mean(
                        np.nan_to_num(
                            sorted(x)[
                                round(len(x) * 25 / 100) : round(len(x) * 75 / 100)
                            ]
                        )
                    ),
                ),
                ("mean_with_na", np.mean),
                ("min", lambda x: x.min()),
                ("5%", lambda x: x.quantile(0.05)),
                ("25%", lambda x: x.quantile(0.25)),
                ("50%", lambda x: x.quantile(0.50)),
                ("75%", lambda x: x.quantile(0.75)),
                ("95%", lambda x: x.quantile(0.95)),
                ("max", lambda x: x.max()),
                ("count", lambda x: x.count()),
                ("stdev", lambda x: x.std()),
                ("mode", lambda x: x.mode()[0]),
                ("median", lambda x: x.median()),
                ("# > 0", lambda x: (x > 0).sum()),
            ]
        )
        .T.reset_index()
        .rename(index=str, columns={"level_0": "Features", "level_1": "Type"})
    )  # rename columns
    # calculate the size of cluster(count of clientID's)
    clustersize = report[
        (report["Features"] == "dummy") & (report["Type"] == "count")
    ].copy()  # avoid SettingWithCopyWarning
    clustersize.Type = (
        "ClusterSize"  # rename created cluster df to match report column names
    )
    clustersize.Features = "# of Customers"
    clusterproportion = pd.DataFrame(
        clustersize.iloc[:, 2:].values
        / clustersize.iloc[:, 2:].values.sum()  # calculating the proportion of cluster
    )
    clusterproportion[
        "Type"
    ] = "% of Customers"  # rename created cluster df to match report column names
    clusterproportion["Features"] = "ClusterProportion"
    cols = clusterproportion.columns.tolist()
    cols = cols[-2:] + cols[:-2]
    clusterproportion = clusterproportion[cols]  # rearrange columns to match report
    clusterproportion.columns = report.columns
    a = pd.DataFrame(
        abs(
            report[report["Type"] == "count"].iloc[:, 2:].values
            - clustersize.iloc[:, 2:].values
        )
    )  # generating df with count of nan values
    a["Features"] = 0
    a["Type"] = "# of nan"
    a.Features = report[
        report["Type"] == "count"
    ].Features.tolist()  # filling values in order to match report
    cols = a.columns.tolist()
    cols = cols[-2:] + cols[:-2]
    a = a[cols]  # rearrange columns to match report
    a.columns = report.columns  # rename columns to match report
    report = report.drop(
        report[report.Type == "count"].index
    )  # drop count values except cluster size
    report = pd.concat(
        [report, a, clustersize, clusterproportion], axis=0
    )  # concat report with clustert size and nan values
    report["Mark"] = report["Features"].isin(ClusteringVariables)
    cols = report.columns.tolist()
    cols = cols[0:2] + cols[-1:] + cols[2:-1]
    report = report[cols]
    sorter1 = {
        "ClusterSize": 9,
        "ClusterProportion": 8,
        "mean_with_zeros": 7,
        "mean_with_na": 6,
        "max": 5,
        "50%": 4,
        "min": 3,
        "25%": 2,
        "75%": 1,
        "# of nan": 0,
        "# > 0": -1,
        "sum_with_na": -2,
    }
    report = (
        report.assign(
            Sorter1=lambda x: x.Type.map(sorter1),
            Sorter2=lambda x: list(reversed(range(len(x)))),
        )
        .sort_values(["Sorter1", "Mark", "Sorter2"], ascending=False)
        .drop(["Sorter1", "Sorter2"], axis=1)
    )
    report.columns.name = ""
    report = report.reset_index()
    report.drop(columns=["index"], inplace=True)
    return report


if __name__ == "__main__":
    import doctest

    doctest.testmod()
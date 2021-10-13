import streamlit as st
import pandas as pd
import numpy as np
import os
import matplotlib.pyplot as plt
import seaborn as sns
from PIL import Image,ImageFilter,ImageEnhance

st.title("Iris EDA App")
st.subheader("EDA Web App with Streamlit ")

my_dataset = "iris.csv"
@st.cache(persist=True)
def explore_data(dataset):
	df = pd.read_csv(os.path.join(dataset))
	return df


data = explore_data(my_dataset)

# Show Dataset
if st.checkbox("Preview DataFrame"):
	
	if st.button("Head"):
		st.write(data.head())
	if st.button("Tail"):
		st.write(data.tail())
	else:
		st.write(data.head(2))

# Show Entire Dataframe
if st.checkbox("Show All DataFrame"):
	st.dataframe(data)
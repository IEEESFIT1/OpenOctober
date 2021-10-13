import 'package:flutter/material.dart';
import 'package:flutter_catalog/widgets/homeWidgets/addToCart.dart';
import 'package:velocity_x/velocity_x.dart';
import 'package:flutter_catalog/models/catalog.dart';
import 'package:flutter_catalog/pages/homeDetail.dart';
import 'package:flutter_catalog/widgets/homeWidgets/catalogImage.dart';

class CatalogList extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return !context.isMobile
        ? GridView.builder(
            gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
                crossAxisCount: 2, crossAxisSpacing: 20.0),
            shrinkWrap: true,
            itemCount: CatalogModel.items.length,
            itemBuilder: (context, index) {
              final catalog = CatalogModel.items[index];
              return InkWell(
                onTap: () => Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => HomeDetailsPage(catalog: catalog),
                  ),
                ),
                child: CatalogItem(catalog: catalog),
              );
            },
          )
        : ListView.builder(
            shrinkWrap: true,
            itemCount: CatalogModel.items.length,
            itemBuilder: (context, index) {
              final catalog = CatalogModel.items[index];
              return InkWell(
                onTap: () => Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => HomeDetailsPage(catalog: catalog),
                  ),
                ),
                child: CatalogItem(catalog: catalog),
              );
            },
          );
  }
}

class CatalogItem extends StatelessWidget {
  final Item catalog;

  const CatalogItem({Key key, @required this.catalog})
      : assert(catalog != null),
        super(key: key);

  @override
  Widget build(BuildContext context) {
    var children2 = [
      Hero(
          tag: Key(catalog.id.toString()),
          child: CatalogImage(image: catalog.image)),
      Expanded(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            catalog.name.text.lg.bold.color(context.accentColor).make(),
            catalog.descriptn.text.textStyle(context.captionStyle).make(),
            10.heightBox,
            ButtonBar(
              alignment: MainAxisAlignment.spaceBetween,
              buttonPadding: EdgeInsets.zero,
              children: [
                "₹ ${catalog.price}".text.bold.xl.make(),
                AddToCart(
                  catalog: catalog,
                )
              ],
            ).pOnly(right: 8.0)
          ],
        ).p(context.isMobile ? 0 : 16),
      )
    ];
    return VxBox(
            child: context.isMobile
                ? Row(
                    children: children2,
                  )
                : Column(
                    children: children2,
                  ))
        .color(context.cardColor)
        .roundedLg
        .square(150)
        .make()
        .py12();
  }
}

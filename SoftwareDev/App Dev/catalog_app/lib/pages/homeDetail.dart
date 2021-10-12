import 'package:flutter/material.dart';
import 'package:flutter_catalog/models/catalog.dart';
import 'package:flutter_catalog/widgets/homeWidgets/addToCart.dart';
import 'package:velocity_x/velocity_x.dart';

class HomeDetailsPage extends StatelessWidget {
  final Item catalog;

  const HomeDetailsPage({Key key, @required this.catalog})
      : assert(catalog != null),
        super(key: key);
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: context.canvasColor,
      bottomNavigationBar: Container(
        color: context.cardColor,
        child: ButtonBar(
          alignment: MainAxisAlignment.spaceBetween,
          buttonPadding: EdgeInsets.zero,
          children: [
            "₹ ${catalog.price}".text.bold.xl4.make(),
            AddToCart(
              catalog: catalog,
            ).wh(150, 50),
          ],
        ).p32(),
      ),
      appBar: AppBar(backgroundColor: Colors.transparent),
      body: SafeArea(
        bottom: false,
        child: Column(
          children: [
            Hero(
                    tag: Key(catalog.id.toString()),
                    child: Image.network(catalog.image))
                .h32(context),
            Expanded(
              child: VxArc(
                height: 20.0,
                arcType: VxArcType.CONVEY,
                edge: VxEdge.TOP,
                child: Container(
                  color: context.cardColor,
                  width: context.screenWidth,
                  child: Column(
                    children: [
                      catalog.name.text.xl4.bold
                          .color(context.accentColor)
                          .make()
                          .p16(),
                      catalog.descriptn.text.xl
                          .textStyle(context.captionStyle)
                          .make(),
                      10.heightBox,
                      "Tempor ipsum ut dolor invidunt elitr, sit invidunt consetetur justo dolores lorem accusam rebum at. Ipsum dolor sed et diam duo ipsum, invidunt sea invidunt amet justo dolores sed. Aliquyam labore dolor elitr ipsum clita takimata, sadipscing dolor eirmod gubergren vero sit dolores sed. Consetetur et no nonumy sanctus dolore."
                          .text
                          .sm
                          .textStyle(context.captionStyle)
                          .make()
                          .p20()
                    ],
                  ).py32(),
                ),
              ),
            )
          ],
        ),
      ),
    );
  }
}

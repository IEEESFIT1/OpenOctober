import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_catalog/core/store.dart';
import 'package:flutter_catalog/models/cart.dart';
import 'dart:convert';
import 'package:flutter_catalog/models/catalog.dart';
import 'package:flutter_catalog/utilities/routes.dart';
import 'package:flutter_catalog/widgets/homeWidgets/catalogHeader.dart';
import 'package:flutter_catalog/widgets/homeWidgets/catalogList.dart';
import 'package:velocity_x/velocity_x.dart';
import 'package:http/http.dart' as http;

class HomePage extends StatefulWidget {
  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  @override
  void initState() {
    // ignore: todo
    // TODO: implement initState
    super.initState();
    loadData();
  }

  Future<void> loadData() async {
    final url = Uri.parse("https://jsonkeeper.com/b/90MO");
    await Future.delayed(Duration(seconds: 2));
    // final catalogJSON =
    //     await rootBundle.loadString("assets/files/catalog.json");
    final response = await http.get(url);
    final catalogJSON = response.body;

    final decoded = jsonDecode(catalogJSON);
    final productData = decoded["products"];
    CatalogModel.items =
        List.from(productData).map<Item>((item) => Item.fromMap(item)).toList();
    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    final _cart = (VxState.store as Store).cart;
    return Scaffold(
        backgroundColor: context.canvasColor,
        floatingActionButton: VxBuilder(
          builder: (context, store, status) => FloatingActionButton(
            backgroundColor: context.theme.buttonColor,
            onPressed: () => Navigator.pushNamed(context, Routes.cartRoute),
            child: Icon(
              CupertinoIcons.cart,
            ),
          ).badge(
              color: context.cardColor,
              size: 20,
              count: _cart.items.length,
              textStyle: TextStyle(
                  color: context.accentColor, fontWeight: FontWeight.bold)),
          mutations: {AddMutation, RemoveMutation},
        ),
        body: SafeArea(
          child: Container(
            padding: Vx.m32,
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                CatalogHeader(),
                if (CatalogModel.items != null && CatalogModel.items.isNotEmpty)
                  CatalogList().py16().expand()
                else
                  CircularProgressIndicator().centered().expand(),
              ],
            ),
          ),
        ));
  }
}

import 'package:flutter_catalog/models/cart.dart';
import 'package:flutter_catalog/models/catalog.dart';
import 'package:velocity_x/velocity_x.dart';

class Store extends VxStore {
  CatalogModel catalog;
  CartModel cart;

  Store() {
    catalog = CatalogModel();
    cart = CartModel();
    cart.catalog = catalog;
  }
}

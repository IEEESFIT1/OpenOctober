import 'package:flutter_catalog/core/store.dart';
import 'package:flutter_catalog/models/catalog.dart';
import 'package:velocity_x/velocity_x.dart';

class CartModel {
  //Catalog field
  CatalogModel _catalog;

  //Storing IDs of each item
  final List<int> _itemIDs = [];

  //Get Catalog
  CatalogModel get catalog => _catalog;

  //Set Catalog
  set catalog(CatalogModel newCatalog) {
    assert(newCatalog != null);
    _catalog = newCatalog;
  }

  //Get Items in the cart
  List<Item> get items => _itemIDs.map((id) => _catalog.getByID(id)).toList();

  //Get Total Price
  num get totalPrice =>
      items.fold(0, (total, current) => total + current.price);
}

class AddMutation extends VxMutation<Store> {
  final Item item;

  AddMutation(this.item);

  @override
  perform() {
    store.cart._itemIDs.add(item.id);
  }
}

class RemoveMutation extends VxMutation<Store> {
  final Item item;

  RemoveMutation(this.item);

  @override
  perform() {
    store.cart._itemIDs.remove(item.id);
  }
}

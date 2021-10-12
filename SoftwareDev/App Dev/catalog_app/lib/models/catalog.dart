import 'dart:convert';

class CatalogModel {
  static List<Item> items;
  //To get an item from it's ID
  Item getByID(int id) =>
      items.firstWhere((element) => element.id == id, orElse: null);

  //To get an item from it's position
  Item getByPosition(int pos) => items[pos];
}

class Item {
  final int id;
  final String name;
  final String descriptn;
  final num price;
  final String color;
  final String image;

  Item({
    this.id,
    this.name,
    this.descriptn,
    this.price,
    this.color,
    this.image,
  });

  Item copyWith({
    int id,
    String name,
    String descriptn,
    num price,
    String color,
    String image,
  }) {
    return Item(
      id: id ?? this.id,
      name: name ?? this.name,
      descriptn: descriptn ?? this.descriptn,
      price: price ?? this.price,
      color: color ?? this.color,
      image: image ?? this.image,
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'name': name,
      'descriptn': descriptn,
      'price': price,
      'color': color,
      'image': image,
    };
  }

  factory Item.fromMap(Map<String, dynamic> map) {
    if (map == null) return null;
    return Item(
      id: map['id'],
      name: map['name'],
      descriptn: map['descriptn'],
      price: map['price'],
      color: map['color'],
      image: map['image'],
    );
  }

  String toJson() => json.encode(toMap());

  factory Item.fromJson(String source) => Item.fromMap(json.decode(source));

  @override
  String toString() {
    return 'Item(id: $id, name: $name, descriptn: $descriptn, price: $price, color: $color, image: $image)';
  }

  @override
  bool operator ==(Object other) {
    if (identical(this, other)) return true;

    return other is Item &&
        other.id == id &&
        other.name == name &&
        other.descriptn == descriptn &&
        other.price == price &&
        other.color == color &&
        other.image == image;
  }

  @override
  int get hashCode {
    return id.hashCode ^
        name.hashCode ^
        descriptn.hashCode ^
        price.hashCode ^
        color.hashCode ^
        image.hashCode;
  }
}

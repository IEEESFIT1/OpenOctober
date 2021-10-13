import 'package:flutter/material.dart';
import 'package:flutter_catalog/core/store.dart';
import 'package:flutter_catalog/pages/cartPage.dart';
import 'package:flutter_catalog/pages/loginPage.dart';
import 'package:flutter_catalog/utilities/routes.dart';
import 'package:flutter_catalog/widgets/themes.dart';
import 'package:velocity_x/velocity_x.dart';
import 'pages/homepage.dart';

void main() {
  runApp(VxState(
    store: Store(),
    child: MyApp(),
  ));
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      themeMode: ThemeMode.system,
      theme: MyTheme.lightTheme(context),
      darkTheme: MyTheme.darkTheme(context),
      debugShowCheckedModeBanner: false,
      initialRoute: Routes.loginRoute,
      routes: {
        "/": (context) => LoginPage(),
        Routes.homeRoute: (context) => HomePage(),
        Routes.loginRoute: (context) => LoginPage(),
        Routes.cartRoute: (context) => CartPage(),
      },
    );
  }
}

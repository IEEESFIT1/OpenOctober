import 'package:cross_platform_mobile_app/home.dart';
import 'package:cross_platform_mobile_app/main_screens/splash.dart';
import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // You need a MaterialApp or a WidgetsApp around your widget. They provide the MediaQuery. When you call .of(context) flutter will always look up the widget tree to find the widget.
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      initialRoute: Splash.id,
      routes: {
        Home.id: (context) => Home(),
        Splash.id: (context) => Splash(),
      },
    );
  }
}

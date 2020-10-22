import 'dart:async';

import 'package:flutter/material.dart';

import '../home.dart';

class Splash extends StatefulWidget {
  static String id = '/Splash';

  @override
  _SplashState createState() => _SplashState();
}

class _SplashState extends State<Splash> {
  @override
  // void initState() {
  //   super.initState();
  //   startTime();
  // }

  // startTime() async {
  //   var _duration = new Duration(seconds: 3);
  //   return new Timer(_duration, navigationPage);
  // }
  //
  // void navigationPage() {
  //   Navigator.pushNamed(context, Home.id);
  // }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          Container(
            decoration: BoxDecoration(
              gradient: LinearGradient(
                begin: Alignment.topLeft,
                end: Alignment.bottomRight,
                colors: [Color(0xffDBA6FE), Color(0xff827EFD)],
              ),
            ),
          ),
          Row(
            children: [
              new Text("left"),
              new Expanded(
                child: Text("right"),
              ),
            ],
          )
        ],
      ),
    );
    // return Scaffold(
    //     backgroundColor: const Color(0xffffffff),
    //     body: Container(
    //       height: MediaQuery.of(context).size.height,
    //       width: MediaQuery.of(context).size.width,
    //       decoration: BoxDecoration(
    //         image: DecorationImage(
    //           fit: BoxFit.cover,
    //           image: AssetImage(
    //             'assets/images/splash_gif.gif',
    //           ),
    //         ),
    //       ),
    //       child: Stack(
    //         children: [
    //           Positioned(
    //             top: MediaQuery.of(context).size.height * 0.85,
    //             left: MediaQuery.of(context).size.width * 0.47,
    //             child: Container(
    //               height: 35,
    //               width: 35,
    //               child: CircularProgressIndicator(
    //                 valueColor: new AlwaysStoppedAnimation<Color>(Colors.white),
    //               ),
    //             ),
    //           ),
    //         ],
    //       ),
    //     ));
  }
}

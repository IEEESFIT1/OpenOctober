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
      backgroundColor: Color(0xffFADBED),
      body: Stack(
        children: [
          //top cloud
          Align(
            alignment: Alignment.topRight,
            child: Image.asset(
              'assets/images/top_cloud.png',
              width: 270,
              height: 270,
            ),
          ),
          //center gif
          Align(
            alignment: Alignment.center,
            child: Image.asset(
              'assets/images/splash_gif.gif',
              width: 350,
              height: 350,
            ),
          ),
          //bottom cloud
          Align(
            alignment: Alignment.bottomLeft,
            child: Image.asset(
              'assets/images/bottom_cloud.png',
              width: 299,
              height: 299,
            ),
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

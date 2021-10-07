

// https://stackoverflow.com/questions/57440636/flutter-start-and-stop-timer-using-same-button
// https://stackoverflow.com/questions/57708212/how-to-check-if-a-button-is-pressed
import 'dart:async';
import 'package:numberpicker/numberpicker.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:percent_indicator/percent_indicator.dart';

void main() =>runApp(MaterialApp(
  debugShowCheckedModeBanner: false,
  home: Pomodoro(),
));

class Pomodoro extends StatefulWidget {
  @override


  _PomodoroState createState() => _PomodoroState();

}

class _PomodoroState extends State<Pomodoro> {

  int hour=0;
  int min=0;
  int sec=0;
  bool started =true;
  bool stopped =true;
  int timeForTimer=0;
  String timeToDisplay="Lets Go!";
  double percent=0;
  int TimeInMin=0;
  bool checkTimer=true;
  void start(){
    setState(() {
      started=false;
      stopped=false;
      percent=0;
    });
    timeForTimer=((hour*60*60)+(min*60)+sec);
    percent=timeForTimer/100;
    Timer.periodic(Duration(seconds:1,), (Timer t) {
      setState(() {
        if(timeForTimer<1 || checkTimer==false){
          t.cancel();
          checkTimer=true;
            timeToDisplay="Lets Go!";
            started=true;
            stopped=true;
            percent=0;
            // Navigator.pushReplacement(context, newRoute)
        }
         else if(timeForTimer<60){
           timeToDisplay="00:00:"+timeForTimer.toString();
           timeForTimer=timeForTimer-1;
           percent=percent+0.1;
        }
         else if(timeForTimer<3600){
           int m= timeForTimer ~/ 60;
           int s= timeForTimer-(60*m);
           timeToDisplay="00:"+m.toString()+":"+s.toString();
           timeForTimer=timeForTimer-1;
           percent=percent+0.1;
        }
         else{
           int h= timeForTimer ~/ 3600;
           int t=timeForTimer-(3600*h);
           int m=t ~/60;
           int s= t-(60*m);
           timeToDisplay=h.toString()+":"+m.toString()+":"+s.toString();
           timeForTimer=timeForTimer-1;
           percent=percent+0.1;
        }

      });
    });

  }


  void stop(){
    setState(() {
      started=true;
      stopped=true;
      checkTimer=false;
      // timeToDisplay="00:00:00";

    });
  }

  @override

  Widget build(BuildContext context) {





      return SafeArea(
      child: Scaffold(
        body: Container(
          decoration: BoxDecoration(
            gradient: LinearGradient(
              colors: [Colors.red[900],Colors.red[300]],
              begin: FractionalOffset(0.1,1)
            )
          ),
          width:double.infinity,
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: [
              Padding(padding: EdgeInsets.only(top:18.0),
                child: Text("Pomodoro Clock",
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 40.0,
                ),),

        ),
              Expanded( child: Center(
                child: Text(
                      timeToDisplay,
                        style: TextStyle(
                          color: Colors.white,
                          fontSize: 70.0,

                        ),
                      ),
              ),
        // CircularPercentIndicator(
              //   circularStrokeCap: CircularStrokeCap.round,
              //   percent: percent,
              //   animation: true,
              //   animateFromLastPercent: true,
              //   radius: 250.0,
              //   lineWidth: 20.0,
              //   backgroundColor: Colors.blue[100],
              //   progressColor: Colors.blue[500],
              //   center: Text(
              //     timeToDisplay,
              //       style: TextStyle(
              //         color: Colors.white,
              //         fontSize: 70.0,
              //
              //       ),
              //   ),
              // )
              ),
              SizedBox(height: 30.0,),
              Expanded(child: Container(
                width: double.infinity,
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.only(topRight: Radius.circular(30.0),topLeft: Radius.circular(30.0))
                ),
                child: Padding(
                  padding: EdgeInsets.only(top:30.0,left:20.0,right:20.0),
                  child: Column(
                    children: [
                      Expanded(
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Column(
                            children: [
                              Padding(padding: EdgeInsets.only(bottom: 5.1),
                              child: Text('HH',
                              ),
                              ),
                              NumberPicker.integer(initialValue: hour, minValue: 0 , maxValue: 23, onChanged: (val){
                                setState(() {
                                  hour=val;
                                });
                              })

                            ],
                          ),
                          Column(
                            children: [
                              Padding(padding: EdgeInsets.only(bottom: 5.1),
                                child: Text('MM'),
                              ),
                              NumberPicker.integer(initialValue: min, minValue: 0 , maxValue: 59, onChanged: (val){
                                setState(() {
                                  min=val;
                                });
                              })

                            ],
                          ),
                          Column(
                            children: [
                              Padding(padding: EdgeInsets.only(bottom: 5.1),
                                child: Text('SS'),
                              ),
                              NumberPicker.integer(initialValue: sec, minValue: 0 , maxValue: 59, onChanged: (val){
                                setState(() {
                                  sec=val;
                                });
                              })

                            ],
                          ),

                        ],
                      ),),
                      Padding(
                        padding: const EdgeInsets.all(30.0),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                          children: [
                            RaisedButton(onPressed: started ? start :null,
                            padding:EdgeInsets.symmetric(
                              horizontal: 40.0,
                              vertical: 10.0,
                            ),
                            color: Colors.green,
                            child:Text(
                              'Start',

                            ),
                              shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(15.0),
                              ),
                            ),
                            RaisedButton(onPressed: stopped?null:stop,
                              padding:EdgeInsets.symmetric(
                                horizontal: 40.0,
                                vertical: 10.0,
                              ),
                              color: Colors.red,
                              child:Text(
                                'stop',

                              ),
                              shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(15.0),
                              ),
                            ),
                          ],
                        ),
                      )
                    ],
                  ),
                ),
              )
              )

            ],
          ),
        ),


      ),
    );
  }
}

import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:personal_expenses/widgets/new_transaction.dart';
import 'package:personal_expenses/widgets/user_transaction.dart';
import 'transaction_list.dart';
import '../models/transaction.dart';
void main() {
  runApp(MyApp());
}
class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Expense App',

      home: MyHomePage(),
    );
  }
}
class MyHomePage extends StatelessWidget {


  // String titleInput;
  // String amountInput;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Count Your Expense'),
      ),
      body:SingleChildScrollView(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          children: [

             Container(
                 width: double.infinity,

                 child: Card(
                   color:Colors.blue,
                     child: Text('chart'),
                   elevation: 5,
                 ),
             ),
              UserTransactions(),

          ],
        ),
      )
    );
  }
}


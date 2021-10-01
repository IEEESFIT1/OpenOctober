
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import '../models/transaction.dart';
class TransactionList extends StatelessWidget {
final List<Transaction > transactions;
TransactionList(this.transactions);

  @override
  Widget build(BuildContext context) {
    return Column(

      children: transactions.map((tx){
        return Card(
          child:Row(
            // mainAxisAlignmAxisAlignment.center,
              children:[
                Container(
                  margin:EdgeInsets.symmetric(
                    vertical :10,
                    horizontal: 15,
                  ),
                  decoration:BoxDecoration(
                      border: Border.all(
                        color:Colors.purple,
                        width:2,
                      )
                  ),
                  padding: EdgeInsets.all(10),
                  child:Text(
                    '\$${tx.amount}',
                    style:TextStyle(
                      fontWeight: FontWeight.bold,
                      fontSize:20,
                      color:Colors.purple,
                    ),
                    // tx.amount.toString(),
                  ),
                ),
                Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children:[

                    Text(tx.title,
                        style:TextStyle(
                          fontSize:18,
                          fontWeight:FontWeight.bold,
                        )
                    ),
                    Text(
                      DateFormat.yMMMd().format(tx.date),
                      style:TextStyle(
                        fontWeight: FontWeight.bold,
                        fontSize:15,
                        color:Colors.grey,

                      ),
                    ),
                  ],),
              ]
          ),
        );
      }).toList(),
    );
  }
}

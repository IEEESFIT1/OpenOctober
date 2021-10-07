import 'package:flutter/material.dart';
import 'new_transaction.dart';
import 'transaction_list.dart';
import 'package:personal_expenses/models/transaction.dart';
class UserTransactions extends StatefulWidget {
  @override
  _UserTransactionsState createState() => _UserTransactionsState();
}

class _UserTransactionsState extends State<UserTransactions> {
  final List<Transaction> _userTransaction=[
    Transaction(
      id:'t1',
      title: 'New shoes',
      amount:60.0,
      date: DateTime.now(),
    ),
    Transaction(
      id:'t1',
      title: 'Weekly groceries',
      amount:70.0,
      date: DateTime.now(),
    ),

  ];
  void _addNewTransaction(String txTitle,double txAmount){
    final newTx=Transaction(
      title: txTitle,
      amount:txAmount,
      date: DateTime.now(),
      id:DateTime.now().toString(),

    );
    setState(() {
      _userTransaction.add(newTx);
    });
  }
  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        NewTransaction(_addNewTransaction),
        TransactionList(_userTransaction),
      ],
    );
  }
}

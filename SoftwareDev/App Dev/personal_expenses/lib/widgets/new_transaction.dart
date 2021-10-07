import 'package:flutter/material.dart';

class NewTransaction extends StatelessWidget {
  final Function addTx;
  final titleController=TextEditingController();
  final amountController=TextEditingController();
  NewTransaction(this.addTx);
  @override
  Widget build(BuildContext context) {
    return Card(
      elevation:5,
      child:Container(
        child: Column(
            crossAxisAlignment: CrossAxisAlignment.end,
            children:[

              TextField(decoration: InputDecoration(labelText:'Title'),
                controller: titleController,
              ),
              TextField(decoration: InputDecoration(labelText:'Amount'),
                controller: amountController,
              ),
              FlatButton(child:Text('Add Transaction'),
                onPressed: (){
                addTx(titleController.text,double.parse(amountController.text));
                },
                textColor: Colors.purple,
              )
            ]),
      ),
    );
  }
}

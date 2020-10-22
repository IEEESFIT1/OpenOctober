# by: Imakshat47
import sqlite3
import config as cfg

# DB Interactions
class Database:
    # Connect to DB
    def conn(self):
        print("Database: conenction method called")
        con = sqlite3.connect(cfg.db_name)
        cur = con.cursor()
        query = "create table if not exists " + cfg.table_name + \
            "(pid integer primary key,pname text,price text, qty text,company text, contact text)"
        cur.execute(query)
        con.commit()
        con.close()
        print("Database: conenction method fnished!!\n")

    # Insert into db
    def insert(self, pid, pname, price, qty, company, contact):
        print("Database: Insert method called")
        con = sqlite3.connect(cfg.db_name)
        cur = con.cursor()
        query = "insert into " + cfg.table_name + " values(?,?,?,?,?,?)"
        cur.execute(query, (pid, pname, price, qty, company, contact))
        con.commit()
        con.close()
        print("Database: Insert method fnished!!\n")

    # Show Data in db
    def show(self):
        print("Database: Show method called")
        con = sqlite3.connect(cfg.db_name)
        cur = con.cursor()
        query = "select * from " + cfg.table_name
        cur.execute(query)
        rows = cur.fetchall()
        con.close()
        print("Database: Show method fnished!!\n")
        return rows

    # Delete Row in db
    def delete(self, pid):
        print("Database: Delete method called", pid)
        con = sqlite3.connect(cfg.db_name)
        cur = con.cursor()
        query = "delete from " + cfg.table_name + " where pid=?"
        cur.execute(query, (pid))
        con.commit()
        con.close()
        print("Database: Delete method fnished!!\n")

    # Search in db
    def search(self,  pid="", pname="", price="", qty="", company="", contact=""):
        print("Database: Search method called")
        con = sqlite3.connect(cfg.db_name)
        cur = con.cursor()
        query = "select * from " + cfg.table_name + \
            " where pid=? or pname=? or price=? or qty=? or company=? or contact=?"
        cur.execute(query, (pid, pname, price, qty, company, contact))
        row = cur.fetchall()
        con.close()
        print("Database: Search method fnished!!\n")
        return row

    # Update in db
    def update(self,  pid="", pname="", price="", qty="", company="", contact=""):
        print("Database: Update method called")
        con = sqlite3.connect(cfg.db_name)
        cur = con.cursor()
        query = "update " + cfg.table_name + \
            " set pid=? or pname=? or price=? or qty=? or company=? or contact=? where pid=?"
        cur.execute(query, (pid, pname, price, qty, company, contact, pid))
        row = con.fetchall()
        con.close()
        print("Database: Update method fnished!!\n")
        return row

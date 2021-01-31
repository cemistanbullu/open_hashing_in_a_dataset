# OPEN HASHING IN A DATASET
***

Goal: Searching the max 10 product using hash table 
***

###### Quick Look at OnlineReatail.csv
| InvoiceNo     | StockCode     | Description | Quantity  | InvoiceDate | UnitPrice | CustomerID | Country|
| ------------- |-------------| --------- |------------|-------------| -----|-----| ------|
| 536365      | 85123A | WHITE HANGING HEART T-LIGHT HOLDER0 | 6| 1.12.2010 08:26| 2,55 | 17850 |United Kingdom|
| 536365     | 71053| WHITE METAL LANTERN |6| 1.12.2010 08:26 | 3,39 | 17850 |United Kingdom|
| 536365      | 84406B| CREAM CUPID HEARTS COAT HANGER |8| 1.12.2010 08:26    | 2,75 | 17850 |United Kingdom|

Shape(65535,8)
***

###### Aim
We want to find top 10 product name in the OnlineRetail.csv file with the most efficient way using the hash function. 

###### Steps
1. Prepare the data set in a readable form
2. Store quantity, stockCode and Description,
3. Update the quantity by adding up the quantities as the same item arrives,
4. Sort them with quick sort by using vector,
5. Search top 10 product name in hash table and print.

###### Output
- It gives Product(stockCode), Description (product name) and total quantity.
- It also calculate total elapsed time and prints time after all operations are done.


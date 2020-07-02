# TextQuery-Engin

TextQuery is a program to perform a search query operation in a text.

It allows to combina basic operation into one single query and execute it.

...
Query q = Query("and"s) & Query("the"s) | ~Query("the"s);
...

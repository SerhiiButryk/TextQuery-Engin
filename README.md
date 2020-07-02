# TextQuery-Engin

# Overview

TextQuery is a program to perform a search query operation in a text. It allows to combina basic operation into one single query and execute it.
Here is available 'OR', 'AND' and 'NOT' logic operations on a text query.

# Structure

- src/main.cpp - main src file
- src/core - implementation of classes and interfaces
- src/core/queries - implementation of 'or', 'and' and 'not' query classes

# Usage

Code snippet from src/main.cpp file:

Query q = Query("and"s) & Query("the"s) | ~Query("the"s);

The priority of operators is from left to right. This query means that a text satisfies the condition of a search if it contains "and" and "the" word or, if those words are not found, it can contain any words except "the". If this condition is true a line is found.

auto result = q.eval(textContainer);

The result contains a vector with indexes of lines which corresponds to text.

# Design

![Untitled Diagram](https://user-images.githubusercontent.com/67712866/86328122-fc05db00-bc4c-11ea-8dcb-416ff3efa995.png)

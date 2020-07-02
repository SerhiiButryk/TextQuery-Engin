# TextQuery-Engin

# Overview

TextQuery is a program to perform a search query operation in a text. It allows to combina basic operation into one single query and execute it.
Here is available 'OR', 'AND' and 'NOT' logic operation on a text query.

# Structure

- src/main.cpp - main src file
- src/core - implementation files and interfaces

# Usage

Code snippet from src/main.cpp file:

Query q = Query("and"s) & Query("the"s) | ~Query("the"s);

The priority of operators is from left to right. This query means that a text satisfies the condition of a search if it contains "and" or "the" word or, if those words are not found, it can contain any words except "the". If this condition is true a line is found.

auto result = q.eval(textContainer);

The result contains a vector with indexes of lines which corresponds to text.

# Design


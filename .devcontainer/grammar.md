# Grammar sample

```plantuml
@startebnf stem EBNF
'https://plantuml.com/ebnf
title stem EBNF

(* Characters *)
digit = ? 0-9 ?;
alpha = ? A-z ?;

(* Lexemes *)
int = {digit}-;
var = alpha, {alpha | digit};
dec = int, ".", int;
' s_int = ["+" | "-"], int;
' s_var = ["+" | "-"], var;
' s_dec = ["+" | "-"], dec;

(* Tokens *)
' atom = s_int | s_var | s_dec;
atom = int | var | dec;

(* Operations *)
fact = expr, {"^", expr}-
  | atom;
term = expr, {["*" | "/"], expr}-
  | fact;
expr = "(", expr, ")"
  | [expr], {("+" | "-"), expr}-
  | term;
equa = expr, {"=", expr}-;

(* Statements *)
stmt = (equa | expr), ";";

@endebnf
```


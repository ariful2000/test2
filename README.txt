# test2

(a)

==> Lexemes basically means sequence of meaningful characters. 
    For example if we have, print(a) --> here we have lexemes - print, (, a, )

    Token is basically like a tuple. It will have a token name and the attribute value. For example: token < token-name, attribute-value (symbol table entry) >
    print (a). print = <id, 1>, ( = < ( >, ) = < ) > and x = < id, 2 >

    * int x = 5;

    
    * int main() {
         printf("Test2");
      }

    tokens = 'main', 'int', '(', ')', '{', '}', 'printf', '(', '"Test2"', ')', ';', '}'

    tokens = int (keyword),

    Lexeme = main is identifier, (, ), {, }, these are pantuation tokens   

    Regular Expression: It is basically read by lexical analyzer, valid syntax of programming language. 
    Follows expression rules 

    Regular grammer: we have variables, strings, etc and reg expression follows some rules and that is basically regular grammer or finite automata
    
    
    Expression:
    
    Division             /
    Addition             +
    Subtract             -
    Multiplication       * 
    Module               %
    Greater than         <
    Less than            >
    Less than Equal To     <=
    Greater than Equal To  >=
    Equal To             =
    Not Equal To         !=
    Bracket left         (
    Bracket right        )
    Assignment           A
    short                [0-9]+ l
    byte                 [0-9] c
    long                 [0-9] d
    if                   N
    else                 M 
    while                Q
    start                C
    end                  E
    
    Variable names:
    [a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z]?[a-zA-Z]?  
    


(c) LL grammer: It is basically a grammer for which ll parser can be gnerated. 
    FIRST/FOLLOW or FIRST/FIRST conflicts = no
    LL Grammar should pass no recursion (left hand) and disjoint test (pairwise).
    
(d)   Its not ambiguous because not same rule for multiple things. 
    
    

(b) Production Rules:

<stmt> --> <if_stmt> | <while_stmt> | <as_s> | <block> 
<block> --> `{` { <stmt>`;` } `}`
<first_condit> -->  `first``(`<exp_bool>`)` <stmt> [ `second_condit` <stmt> ]
<reapeat_wh> -->  `wh``(`<exp_bool>`)` <stmt> 
<as_s>  --> `id` `=` <expr>
<expr> --> <term> { (`\`|`%`|`*`) <term> } 
<term> --> <factor> { (`-`|`+`) <factor> }
<factor> --> `id` | `int_lit` | `float_lit` | `(` <expr> `)` 


<zeq> --> <zrel> { (`!=`|`==`) <zrel> }
<zrel> --> <zexpr> { (`<=`|`>=` | `<` | `>`) <zexpr> }   
<zexpr> --> <zterm> { (`%`|`*`|`\`) <zterm> }
<zterm> --> <zfactor> {  (`-`|`+`) <zfactor> }

<zfactor> --> `id` | `int_lit` | `float_lit` | `bool_lit` | `(` <zexpr> `)`
    
    
    
    
    
    
    

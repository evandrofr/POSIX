COMO UTILIZAR:
-Compile o projeto com o comando: gcc example.c -o example
-Você pode executar o programa de dois modos:
--Executar todos os testes -> Rode o executavel sem nenhum argumento. Dentro da pasta src use o comando: ./example
--Executar um teste expecifico -> Rode o executavel com o nome do teste que se quer executar como argumento. Dentro da pasta src use o comando: ./example <Nome do Teste>
---Ex.: ./example test1

COMO O PROJETO FUNCIONA:
- O projeto roda cada teste individualmente em paralelo e com tempo máximo de execução. Isso significa que se um teste tiver algum tipo de erro, não prejudicará a execução dos demais testes e caso o teste demore demais para terminar (ou nunca termine. Ex.: loop infinito), o programa encerrará sua execução depois de um certo tempo.
- O programa devolve três possiveis diferentes saidas para cada teste.
--[PASS] quando o teste executa sem erros e tem resultado positivo.
--[FAIL] quando o teste exucuta sem erros e tem resultado negativo.
--[ERROR] quando o teste realiza alguma operação ilegal ou é encerrado por tempo máximo de execução. (Segue ao lado explicação de qual erro ocorreu).

COMO O PROJETO FOI IMPLEMENTADO:
-  
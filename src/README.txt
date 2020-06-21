COMO UTILIZAR:
-Compile o projeto com o comando: gcc example.c -o example
-Você pode executar o programa de dois modos:
--Executar todos os testes -> Rode o executavel sem nenhum argumento. Dentro da pasta src use o comando: ./example
--Executar um teste expecifico -> Rode o executavel com o nome do teste que se quer executar como argumento. Dentro da pasta src use o comando: ./example <Nome do Teste>
---Ex.: ./example test1

COMO O PROJETO FUNCIONA:
- O projeto roda cada teste individualmente em paralelo e com tempo máximo de execução. Isso significa que se um teste tiver algum tipo de erro, não prejudicará a execução dos demais testes e caso o teste demore demais para terminar (ou nunca termine. Ex.: loop infinito), o programa encerrará sua execução depois de um certo tempo.
- O programa devolve três possiveis diferentes saidas para cada teste.
--[PASS] quando o teste executa sem erros e tem resultado positivo. (VERDE)
--[FAIL] quando o teste exucuta sem erros e tem resultado negativo. (VERMELHO)
--[ERROR] quando o teste realiza alguma operação ilegal (segue ao lado explicação de qual erro ocorreu). (VERMELHO E NEGRITO)
--[TIME] quando o teste é encerrado por tempo máximo de execução. (VERMELHO E NEGRITO)

COMO O PROJETO FOI IMPLEMENTADO:
-  Utilizando os argumentos argc e argv da função main se identica se o usuário deseja realizar um único teste ou todos.
-  É realizado um fork do código principal para cada teste. Desse modo todos os testes rodam de forma independente e em paralelo.
-  Espera-se todos os forks encerrarem antes dos resultados serem mostrados no terminal. Utiliza-se um loop com a função wait() para esperar todos os forks.
-  Todos os resultados são escritos em arquivos de cada testes antes de serem mostrados no terminal. Isso é feito para que os resultados sejam exibidos todos juntos e na ordem correta.
-  Todos os arquivos criados para armazenar os resultados são deletados após a execução.  
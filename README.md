<!--Idea!! CITAR O NÍVIO ZIVIANI-->
<!--DÚVIDAS!!
    1. Pedir um feedback geral tanto do código quanto do readme.
    2. Perguntar se as minhas referências estão sendo realizadas da maneira correta.
    3. Tá grande de mais?
    remember the font: https://www.iconexperience.com/o_collection/search/?q=graph
-->


<div align = "center" >
<img src="https://d1nhio0ox7pgb.cloudfront.net/_img/o_collection_png/green_dark_grey/256x256/plain/dot_matrix.png" width="14%">
</div>

<div align="justify">

<div align="center">

# O Algoritmo Guloso

#### Algoritmos e Estrutura de Dados

#### Compatibilidade e Desenvolvimento
![Vscode](https://img.shields.io/badge/VSCode-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white) 
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)  

</div>


## Objetivo
Este repositório apresenta a solução implementada para o desafio proposto na disciplina de Algoritmos e Estruturas de Dados. O problema proposto foi que houvesse um algoritmo que realizasse uma pesquisa e armazenamento de valores contidos em  uma matriz de maneira gulosa.

### Desafio
Um programa que leia $K$ matrizes $N$ x $N$, tal que $N \in \mathbb{Z}$ e $N\geq 0$.

1. Organização de matrizes para processamento.
2. Iniciar a busca de um conjunto de coordenadas em linhas e colunas, sendo essa coordenada pertencente à matriz. Vale ressaltar que a coordenada será estabelecida pelo usuário, ou concebida através da leitura de uma arquivo.
3. São direções válidas para caminhamento:
    
    3.1. Avançar para a próxima coluna.
    
    3.2. Retroceder para a coluna anterior.
    
    3.3. Saltar para a linha de baixo.
    
    3.4. Ir em diagonal para baixo.
4. A direção de escolha deve contem o maior valor adjascente dentre as direções possíveis.
5. Caso haja um valor em comum entre as direções de maior valor, é  necessário que uma regra de caminhamento seja estabelecida. E que esta enquanto padrão seja a melhor decisão de caminhamento.
6. Ao ter como posição atual o elemento de uma matriz posicionado na última linha e coluna simultâneamente, ou seja o elemento na coordenada de maior valor de maior $i$ e $j$, tais que, $i,j \in$ onde $  0 \leq i\leq N$ e $0 \leq j \leq N$.

<!--Prioridade alta-->
### Solução

### Imagens e exemplos de implementação:
//Usando uma matriz de exemplo com latex
$\begin{bmatrix}
1 & 0 & 0 & 0\\
0 & 2 & 0 & 0\\
0 & 0 & \ddots & 0\\
0 & 0 & 0 & n
\end{bmatrix}$



## Reflexões e Aprendizados

### O que é um Algoritmo Guloso?
"Um algoritmo guloso sempre faz a escolha que parece ser a melhor no momento em questão. 
Isto é, faz uma escolha localmente ótima, na esperança de que essa escolha leve a uma solução globalmente ótima." 
<br>
<strong>Algoritmos: teoria e prática, de Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest e Clifford Stein, tradução da 3ª edição</strong>
<div>

### Reavaliando a Implementação de um Algoritmo Guloso
Com o intuito de preparar os alunos para a disciplina de Algoritmos e Estruturas de Dados dentro de um contexto onde os mesmos tivessem de ser avaliados em um período limitado de tempo, o desenvolvimento do desafio será avaliado diante da documentação e tentativa de construir um algoritmo guloso que resolvesse o problema apresentado.

Contudo, é importante ressaltar que a implementação de algoritmos gulosos necessita de um estudo aprofundado em outros cenários antes de ser implementado.

Considerando isso, são propostos por Cormen(2012) os Elementos da Estratégia Gulosa, ou seja, a projeção de algoritmos gulosos conta com a seguinte sequência de etapas:

1. "Projetar o problema [...] como um problema no qual fazemos uma escolha e ficamos com um único subproblema para resolver"(CORMEN, 2012, p.354).<br><br>
2. "Provar que sempre existe uma solução ótima para o problema original que usa a escolha gulosa, de modo que a escolha gulosa é sempre segura"(CORMEN, 2012, p.354)."<br><br>
3. "Demonstrar subestrutura ótima, mostrando que, tendo feito a escolha gulosa, o que resta é o subproblema com a seguinte propriedade: se combinamos uma solução ótima para o subproblema com a escolha que fizemos, chegamos a uma solução ótima para o problema original"(CORMEN, 2012, p.354).<br><br>

</p>

<!--Prioridade baixa-->## Bibliotecas

## Compilação e Execução
Para compilação e execução do código é necessário que seja criado um arquivo Makefile. Para uso deste arquivo da forma correta, siga as diretrizes de execução abaixo:

<table>

<tr>
<td colspan = '1'><strong>Comandos</strong></td>
<td align = "center" colspan = '1'><strong>Funções</strong></td>
</tr>

<tr>
<td align="center">make clean</td>
<td align="center">Deleta o arquivo executável e todos os arquivos objetos do diretório. (GNU make, 2023)</td>
</tr>
<tr>
<td align="center">make</td>
<td align="center">Compila diferentes partes do programa através do g++ e cria um arquivo executável na pasta build. </td>
</tr>
<tr>
<td align="center">make run </td>
<td align="center">Executa o programa da pasta build após a realização da compilação. (Michel Pires, 2023)</td>
</tr>
</table>

## Referências <!--Idea!! CITAR O NÍVIO ZIVIANI-->

[1] CORMEN, T. H. et al. Introduction to Algorithms, third edition. [s.l.] MIT Press, 2009. Acessador em 20 de Março de 2023.

[2] Michel Pires - Repositório GitHub, @mpiress: GenerateDataToMatrix - Disponível em: https://github.com/mpiress/GenerateDataToMatrix/blob/main/src/mat.h. Acessado em 15 de Março de 2023.

[3] GNU make. Disponível em: <https://www.gnu.org/software/make/manual/make.html>. Acessado em 21 de Março de 2023.

‌
## Contato

<div style="display: inline-block;">
<a href="https://t.me/joaaogg">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/joao-gustavo-silva/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>

<a style="color:black" href="mailto:michel@cefetmg.br?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>joaogu.2001@gmail.com</i>
</a>


</div>

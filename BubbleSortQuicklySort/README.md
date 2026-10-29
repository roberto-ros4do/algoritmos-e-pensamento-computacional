# ClassificaNotas — Classificação de Notas de Estudantes

## Objetivo

Desenvolver uma aplicação em linguagem C para organizar médias finais de estudantes utilizando os algoritmos de ordenação Bubble Sort e Quick Sort.

## Situação-problema

Ao final de um período letivo, uma escola precisa organizar as médias dos estudantes para identificar os melhores desempenhos acadêmicos.

A aplicação utiliza um conjunto de 10 médias e realiza a classificação em ordem decrescente, da maior para a menor nota.

## Algoritmos utilizados

### Bubble Sort

O Bubble Sort percorre o vetor comparando elementos vizinhos. Quando uma nota é menor que a seguinte, suas posições são trocadas.

O processo se repete até que todas as notas estejam organizadas em ordem decrescente.

### Quick Sort

O Quick Sort utiliza a estratégia de divisão e conquista.

O algoritmo escolhe um elemento como pivô, reorganiza as notas maiores e menores em relação a ele e ordena recursivamente as partes resultantes.

## Funcionamento

O programa:

1. Inicializa um vetor com 10 médias de estudantes.
2. Exibe as médias na ordem original.
3. Cria duas cópias dos dados originais.
4. Ordena a primeira cópia utilizando Bubble Sort.
5. Ordena a segunda cópia utilizando Quick Sort.
6. Apresenta os resultados dos dois algoritmos.

## Como executar

É necessário possuir um compilador C, como o GCC.

Para compilar:

```bash
gcc main.c -o classifica-notas
```

Para executar no Windows:

```bash
.\classifica-notas.exe
```

Para executar no Linux:

```bash
./classifica-notas
```

## Resultado esperado

```text
Notas originais:
7.5 9.0 6.2 8.7 5.5 10.0 7.0 4.8 8.0 6.5

Notas ordenadas com Bubble Sort:
10.0 9.0 8.7 8.0 7.5 7.0 6.5 6.2 5.5 4.8

Notas ordenadas com Quick Sort:
10.0 9.0 8.7 8.0 7.5 7.0 6.5 6.2 5.5 4.8
```

## Conclusão

Os dois algoritmos conseguiram organizar corretamente as médias dos estudantes.

O Bubble Sort utiliza comparações sucessivas entre elementos vizinhos, enquanto o Quick Sort divide o problema em partes menores.

Embora ambos produzam o mesmo resultado, o Quick Sort geralmente apresenta melhor desempenho para conjuntos maiores de dados.

## Tecnologias utilizadas

- Linguagem C
- Compilador GCC
- Git e GitHub
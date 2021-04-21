# Atividade-semi-presencial-24-04
Atividade semi presencial do dia 24/04 da disiciplina de Algoritmos e Programação da ULBRA Canoas. 

Definição: https://docs.google.com/document/d/1aLaRuKbEcCL_W4Z_9z_ylObppzt737XmG5FEE7kGgzs/edit

# Questão 2 (dissertativa):

a)

Média geométrica

A média geométrica é usada em geral para dados que tendem a se comportar similar a uma progressão geometrica, ex: (3, 9, 27, 81) ; (3, 12, 16, 32). Geralmente é usada em problemas de volume e área de formas geométricas, mas tem usos para matemática financeira.

A minha implementação foi baseando simplesmente na fórmula da média geométrica:

![image](https://user-images.githubusercontent.com/79986367/115625015-d5935800-a2d1-11eb-8213-6022e25caa54.png)

Para ser possível usar um numero dimensionavel de numeros, utilizei um array de double para a operação. Uma passo muito importante é remover os zeros e numeros negativos da sequencia. Considerando somentes os numeros positivos, teremos que multiplicar elese todos e pegar a quantidade deles e usar a formula.

 Média Harmonica

A média harmonica em geral é usada quando se lida com grandezes inversamente proporcionais, por exemplo a velocidade média, a vazão da água, a densidade e etc. Algo importante de ser notar é que os valores que precisam ser usados são invertidos.

A minha implementação foi seguindo a fórmula:

![image](https://user-images.githubusercontent.com/79986367/115626015-48e99980-a2d3-11eb-8948-f666fc216ede.png)

Aqui também utilizei arrays e removi os numeros negativos e zeros. O código não ficou muito diferente da média geométrica, nesse caso somei todos os  inversos numeros válidos, peguei a quantidade de numeros validos e dividi pela soma anterior.

b)

No meu caso consegui escrever um unico código que para 5 ou 10 numeros é exatamente igual, aceita mesmo qauntidade muito grandes, porém não testei para verificar se funcionaria sem problemas. Mas agora que vou fazer com meu grupo de uma maneira sem loop's, acredito que será muitos if e elses juntos, e cada vez que aumenta quantidade de numeros precisa mexer em toda cadeia

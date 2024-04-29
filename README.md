Push_Swap es un proyecto de algoritmia simple y muy efectivo: tienes que ordenar
datos.

Tienes a tu disposición un conjunto de valores enteros, 2 stacks y un conjunto de
instrucciones para manipular ambos stacks.

¿Cuál es tu objetivo? Escribir un programa en C llamado push_swap. El programa calculará y mostrará en la salida estándar el programa más pequeño, creado con las instrucciones de lenguaje Push swap, que ordene los números enteros recibidos como argumentos.

<h1>1. Las reglas</h1>

• Tienes 2 stacks, llamados a y b.

• Para empezar:

_◦ El stack a contiene una cantidad aleatoria de números positivos y/o negativos,
nunca duplicados._

_◦ El stack b está vacío._

• El objetivo es ordenar los números del stack a en orden ascendente. Para hacerlo
tienes las siguientes operaciones a tu disposición:


**sa swap a:** Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.

**sb swap b:** Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.

**ss:** swap a y swap b a la vez.

**pa push a:** Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

**pb push b:** Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.

**ra rotate a:** Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.

**rb rotate b:** Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.

**rr:** ra y rb al mismo tiempo.

**rra reverse rotate a:** Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

**rrb reverse rotate b:** Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.

**rrr:** rra y rrb al mismo tiempo.

<h1>2. El programa: “push_swap”</h1>

_Tu programa deberá cumplir la siguientes normas:_

• Debes escribir un programa llamado push_swap que recibirá como argumento el
stack a con el formato de una lista de enteros. El primer argumento debe ser el que
esté encima del stack (cuidado con el orden).

• El programa debe mostrar la lista de instrucciones más corta posible para ordenar
el stack a, de menor a mayor, donde el número menor se sitúe en la cima del stack.

• Las instrucciones deben separarse utilizando un “\n” y nada más.

• El objetivo es ordenar el stack con el mínimo número de operaciones posible. Durante la evaluación compararemos el número de instrucciones obtenido por tu programa con un rango de instrucciones máximo. Si tu programa muestra una lista demasiado larga o si el resultado no es correcto, tu nota será 0.

• Si no se especifican parámetros, el programa no deberá mostrar nada y deberá devolver el control al usuario.

• En caso de error, deberá mostrar Error seguido de un “\n” en la salida de errores estándar. Algunos de los posibles errores son: argumentos que no son enteros,
argumentos superiores a un número entero, y/o encontrar números duplicados.

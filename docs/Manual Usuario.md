# Manual de Usuario - Juego de Batalla Naval

## Descripción
El BATTLESHIP en C++ es un juego de dos jugadores en el que cada jugador intenta hundir los barcos del otro. Cada jugador coloca estratégicamente sus barcos en un tablero y luego intenta adivinar las posiciones de los barcos del oponente para atacarlos.

## Instrucciones para jugar
- El juego se juega en una consola de texto.
- Al iniciar el juego, se le pedirá a cada jugador que coloque sus barcos en el tablero.
- Cada barco tiene una longitud específica y se puede colocar en posición horizontal o vertical.
- Los jugadores deben ingresar la orientación del barco (0 para horizontal, 1 para vertical), seguido de las coordenadas X e Y de la posición inicial del barco.
- Por ejemplo, para colocar un barco horizontal de longitud 3 en la posición (4, 2), el jugador debe ingresar: 0 4 2.
- Los jugadores deben colocar todos sus barcos uno por uno en el tablero.
- Después de que ambos jugadores hayan colocado sus barcos, el juego comenzará.
- Los jugadores se turnarán para realizar ataques ingresando las coordenadas de ataque (X e Y).
- Si el ataque golpea un barco, se mostrará una 'X' en el tablero del oponente. Si el ataque falla, se mostrará una 'O'.
- El juego continúa hasta que un jugador haya hundido todos los barcos del oponente.
- El jugador que hunda todos los barcos del oponente primero será declarado como ganador.

## Controles
- Durante el juego, se solicitarán varias entradas al jugador. Debe ingresar los valores solicitados utilizando el teclado de la computadora.
- Para colocar un barco, debe ingresar la orientación (0 o 1), seguido de las coordenadas X e Y.
- Para realizar un ataque, debe ingresar las coordenadas X e Y del lugar al que desea atacar.

## Ejemplo de juego
- A continuación se muestra un ejemplo de cómo se vería el juego en la consola:

  INSTRUCCIONES (JUGADOR 1)

  Estás a punto de colocar tus barcos. El formato debe ser:
  Orientación (0: Horizontal, 1: Vertical), coordenada X (fila superior), coordenada Y (columna izquierda)
  Ejemplo: 0 7 2 Esto colocaría un barco comenzando en X:7 Y:2 yendo horizontal

  Coloca la posición del Portaaviones que tiene una longitud de 5 unidades.
  ¿Dónde quieres que se coloque? 0 7 2

  ... (instrucciones para colocar los demás barcos del jugador 1)

  INSTRUCCIONES (JUGADOR 2)

  Estás a punto de colocar tus barcos. El formato debe ser:
  Orientación (0: Horizontal, 1: Vertical), coordenada X (fila superior), coordenada Y (columna izquierda)
  Ejemplo: 0 7 2 Esto colocaría un barco comenzando en X:7 Y:2 yendo horizontal

  Coloca la posición del Portaaviones que tiene una longitud de 5 unidades.
  ¿Dónde quieres que se coloque? 1 3 5

  ... (instrucciones para colocar los demás barcos del jugador 2)

  TURNO DEL JUGADOR 1

  TABLERO DEL JUGADOR 1:
  ...

  Ingresa las coordenadas de ataque: 5 3

  TABLERO DEL JUGADOR 2:
  ...

  TURNO DEL JUGADOR 2

  TABLERO DEL JUGADOR 1:
  ...

  Ingresa las coordenadas de ataque: 2 6

  TABLERO DEL JUGADOR 2:
  ...

  ... (el juego continúa hasta que se hunden todos los barcos de un jugador)

  ¡Felicitaciones! ¡El jugador 1 ha ganado la batalla!

## Fin del juego:
- Una vez que se hunden todos los barcos de un jugador, se mostrará un mensaje de felicitación al jugador ganador.
- Puedes presionar cualquier tecla para cerrar el juego después de que se muestre el mensaje de felicitación.

¡Eso es todo! Ahora estás listo para jugar al juego de Batalla Naval utilizando este código. ¡Diviértete!

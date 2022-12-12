Pac-Man parte 1


En el proyecto de pac man parte 1,hemos realizado un simulación de cómo sería el videojuego Pac-man con c++ ejecutándose en la consola de windows


En él hemos realizado, el sistema de puntuación,el personaje y su respectivo movimiento,terminar el juego al pulsar,el sistema de teletransporte y las paredes.


Para ello hemos utilizado 4 voids principalmente: Setup,Input,Logic y Draw.


En Setup,hemos generado el mapa,los puntos y el personaje,además de crear la puntuación total en el


En Input, hemos asignado que input se corresponde a cada tecla.


En Logic, hemos asignado que inputs se corresponde a que acción dentro del juego, además de hacer el teletransporte y hacer que cuando se recojan todos los puntos la bool “run” pase a ser falsa.


En Draw,es usada para poner el personaje en pantalla y hacer que la misma se refresque, además de mostrar la puntuación en pantalla.


Finalmente hemos usado un int main, para hacerle saber al programa el orden que debe ejecutar las diferentes voids y qué hacer cuando el bool “run” pasa a ser falso (acaba el juego).
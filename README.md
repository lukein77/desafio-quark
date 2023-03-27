# Cotizador
### Desafío final del curso C++ de Quark Academy.

El programa permite realizar cotizaciones de diferentes prendas de una tienda de ropa.

---
Para realizar una cotizacion siga las siguientes instrucciones:
1) Ingrese la opción "2" en el menú principal.
2) Seleccione el código de prenda a cotizar.
3) Ingrese el precio unitario de la prenda.
4) Ingrese la cantidad de unidades a cotizar.
5) Si la cantidad en stock es suficiente, se realizará la cotización. Puede ingresar 0 en cualquier momento para cancelar la operación y regresar al menú anterior.

Para ver el historial de cotizaciones, ingrese la opción "1" en el menú principal.

Para el cálculo del precio final de la cotización, se siguen las siguientes reglas:

**Tipo de prenda:**

1) Si la camisa es de tipo manga corta, el precio se rebaja en un 10%.
2) Si la camisa tiene cuello mao, el precio aumenta en un 3%.
3) Si la camisa es de manga corta y cuello mao, se aplican las dos reglas anteriores (en el orden establecido).
4) Si el pantalón es chupín, el precio se rebaja en un 12%. 

**Calidad de prenda:**

5) Si la calidad de la prenda es Standard, el precio no se modifica.
6) Si la calidad de la prenda es Premium, el precio aumenta en un 30%.
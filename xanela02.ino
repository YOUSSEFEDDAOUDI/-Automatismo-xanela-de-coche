 #define ABRIR  11
 #define CERRAR 12       
 #define PULSADOR 10 
 #define fcABRIR 9
 #define fcCERRAR 8 

 bool motorActual = false;
 bool estado = 0;
 int tAcero=7000; 
 int contador = 0;

void setup(){
            // Inicializa los pines
  pinMode(ABRIR, OUTPUT);
  pinMode(CERRAR, OUTPUT);
  pinMode(PULSADOR, INPUT_PULLUP);
  pinMode(fcABRIR, INPUT_PULLUP);
  pinMode(fcCERRAR, INPUT_PULLUP);
  Serial.begin(9600);
  int contadoror=100;
}
void loop (){
  if(digitalRead(PULSADOR)){
      if(contador>0){
          contador=0;
      }
    else {
    	estado = !estado;
        contador = 100;    
   	}
   
    	while(digitalRead(PULSADOR)){
      	delay(20);
  	}
  }
  
  
    if(digitalRead(fcABRIR)){ 
          if(contador>0){
            contador=0;
     	}
    }
  
     if(digitalRead(fcCERRAR)){ 
          if(contador>0){
            contador=0;
     	}
    }
  
  
  
      if(contador>0){
        if(estado==0){
        digitalWrite(ABRIR,HIGH); 
        digitalWrite(CERRAR,LOW);
       delay(70);
        contador--;
        }
          

  else {
  
        digitalWrite(ABRIR,LOW);      
        digitalWrite(CERRAR,HIGH); 
       delay(70);
        contador--;
  } 
  
      }
else { 
        digitalWrite(ABRIR,LOW);
        digitalWrite(CERRAR,LOW);
       delay(100);
        if (motorActual) {
      digitalWrite(ABRIR,LOW); 
    } else {
      digitalWrite(CERRAR, LOW); 
    }
  
    motorActual = !motorActual;
}
    
      }

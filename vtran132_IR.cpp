boolean NCO = 0;
byte  i = 0; 
byte NS = 0; 
unsigned long NC;
 
void setup() {
  TCCR1A = 0;
  TCCR1B = 0;                                   
  TCNT1  = 0;                                   
  TIMSK1 = 1;                                    
  attachInterrupt(0, readIR, CHANGE);       
}
 
void readIR() {
  unsigned int timerCount;
    if(NS != 0){
      timerCount = TCNT1;                        
      TCNT1 = 0;                                  
    }
    switch(NS){
      case 0 :                                   
        TCNT1  = 0;                                  
        TCCR1B = 2;                                 
        NS = 1;                              
        i = 0;
        return;
      case 1 :                                     
        if ((timerCount > 19000) || (timerCount < 17000)) {         
        NS = 0;                            
        TCCR1B = 0;                               
      }
    else
      NS = 2;                             
    return;
   case 2 :                                      
    if ((timerCount > 10000) || (timerCount < 8000)) {
      NS = 0;                             
      TCCR1B = 0;                                
    }
    else
      NS = 3;                             
    return;
   case 3 :                                     
    if ((timerCount > 1400) || (timerCount < 800)) {           
      TCCR1B = 0;                              
      NS = 0;                             
    }
    else
      NS = 4;                             
    return;
   case 4 :                                     
    if ((timerCount > 3600) || (timerCount < 800)) {          
      TCCR1B = 0;                                
      NS = 0;                         
      return;
    }
    if (timerCount > 2000) {                    
      bitSet(NC, (31 - i));
    }              
    else {                                        
      bitClear(NC, (31 - i)); 
    }            
    ++i;
    if (i > 31){                                
      NCO = 1;                               
      detachInterrupt(0);                      )
      return;
    }
    NS = 3;                               
  }
}
 
ISR(TIMER1_OVF_vect) {                          
  NS = 0;                                 
  TCCR1B = 0;                                 
}
 
void loop() {
  if (NCO){                                   
    NCO = 0;                                  
    NS = 0;
    TCCR1B = 0;                                                             
    attachInterrupt(0, readIR, CHANGE);   
  }
}

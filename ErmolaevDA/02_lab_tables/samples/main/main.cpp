# i n c l u d e   " S c a n T a b l e . h " 
 # i n c l u d e   " H a s h T a b l e . h " 
 # i n c l u d e   " S o r t T a b l e . h " 
 # i n c l u d e   " T a b l e . h " 
 # i n c l u d e   " p o l i n o m . h " 
 # i n c l u d e   < s t r i n g > / / ; 
 u s i n g   n a m e s p a c e   s t d ; 
 # d e f i n e   S S   < i n t , s t r i n g > 
 
 # d e f i n e   Z Z   < P o l i n o m , s t r i n g > 
 i n t   m a i n ( )   { 
 
 	 
 	 S o r t T a b l e   S S   A ; 
         A . I n s e r t R e c o r d ( 1 1 ,   " 1 " ) ; 
         A . I n s e r t R e c o r d ( 9 ,   " 2 " ) ; 
         A . I n s e r t R e c o r d ( 8 ,   " 3 " ) ; 
         A . I n s e r t R e c o r d ( 7 ,   " 1 7 7 7 " ) ; 
         A . I n s e r t R e c o r d ( 6 ,   " 1 6 6 8 8 " ) ; 
         A . I n s e r t R e c o r d ( 5 ,   " 6 " ) ; 
         A . I n s e r t R e c o r d ( 4 ,   " 7 " ) ; 
         A . I n s e r t R e c o r d ( 3 ,   " 8 " ) ; 
         A . I n s e r t R e c o r d ( 2 0 0 ,   " 9 " ) ; 
 	 c o u t   < <   A < < e n d l ; 
 
 	 A . S o r t D a t a ( ) ; 
 	 c o u t   < <   A ; 
 
 	 S o r t T a b l e   Z Z   P o l t a b l e ; 
 
 	 P o l i n o m   p 1 ; 
 	 p 1 . s t r _ t o _ p o l y ( " x + y " ) ; 
         P o l t a b l e . I n s e r t R e c o r d ( p 1 ,   " x + y " ) ; 
 	 P o l i n o m   p 2 ; 
 	 p 2 . s t r _ t o _ p o l y ( " 2 x + z ^ 2 " ) ; 
         P o l t a b l e . I n s e r t R e c o r d ( p 2 ,   " 2 x + z ^ 2 " ) ; 
 	 P o l i n o m   p 3 ; 
         P o l t a b l e . I n s e r t R e c o r d ( ( p 2   +   p 1 ) ,   " 2 x + z ^ 2 + x + y " ) ; 
 	 c o u t   < <   P o l t a b l e ; 
 
 	 H a s h T a b l e   Z Z   P o l ; 
         P o l . I n s e r t R e c o r d ( p 1 ,   " x + y " ) ; 
 	 r e t u r n   0 ; 
 } 
 
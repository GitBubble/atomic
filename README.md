# atomic


`Atomic instructions bypass the store buffer or at least they act as if they do - they likely actually use the store buffer, but they flush it and the instruction pipeline before the load and wait for it to drain after, and have a lock on the cacheline that they take as part o the load, and release as part of the store - all to make sure that the cacheline doesn't go away in between and that nobody else can see the store buffer contents while this is going on.
                                                                                 -linus torvald  `



arm/x86/power/itanium/sparc    
   - not sequentially consistant  
   - weak or relaxed memory   
   - so compiler can do optimization  


TSO(total store ordering)
   https://www.cl.cam.ac.uk/~pes20/ppc-supplemental/test7.pdf   
   
   * x86/sparc * :   
     * INC * not guarente atomic, * LOCK; INC * guarente atomic increment      
      compare and swap instruction CMPXCHG do the same thing ...   
      any * write * action visible to other thread.     
   
   * arm/power * :        
      not multiple-copy atomic          
      not guarente any * write * action visible to other hardware thread.           
      let the programmer make decision..        

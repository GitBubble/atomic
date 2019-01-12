# atomic


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

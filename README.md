# atomic


`linus torvald----Atomic instructions bypass the store buffer or at least they act as if they do - they likely actually use the store buffer, but they flush it and the instruction pipeline before the load and wait for it to drain after, and have a lock on the cacheline that they take as part o the load, and release as part of the store - all to make sure that the cacheline doesn't go away in between and that nobody else can see the store buffer contents while this is going on`



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


atomic_perform.cpp comments:


Methods tested
Here is a list of the implemented algorithms with explanations:

Read: reads the current value and increases control counter
Write: reads the old value, increases it and writes it back
Set: writes a loop counter into the protected variable
0: Unlocked
To get a reference to the costs of the locking, the probably race conditions prone flat increment & read was executed.

1: Mutexes
The classical way would be to protect the access to the variable by a mutex usind std::mutex. This is known to have much overhead.

2: Writelock / Writelock
These “should” be cheaper than mutexes. We wanted to see whats happening if you don’t differentiate between read / write. We do pthread wrlock / wrlock for the *nix-es, SRWLock Exclusive / Exclusive on windows

3: Writelock / Readlock
These “should” be cheaper than mutexes. We do pthread wrlock / rdlock for the *nix-es, SRWLock Exclusive / Shared on windows

4: Atomic Read & Write
The new kid in town since C++ 11: Also called lockless. Atomic is here to ensure no races are to be expected while accessing a variable. The possible syntax can result in a very compact code, at which you may not always be aware the ‘a++’ you’re reading is actually involves the overhead of atomic operations. The implementation is strongly dependent on the CPU architecture and its support.

5: Atomic Read “consume”, Atomic Set “release” for setting
This way the expenses of the atomic operation comes quicker to the code readers eye; its using the setter & getter methods. The test case doesn’t increment the int, it simply sets the counter as new value – thus the resulting numbers look different. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_consume for reading, std::memory_order_release for setting..

6: Atomic Read “acquire”, Atomic Set “release” for setting
This way the expenses of the atomic operation comes quicker to the code readers eye; its using the setter & getter methods. The test case doesn’t increment the int, it simply sets the counter as new value – thus the resulting numbers look different. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_acquire, std::memory_order_release for setting.

7: Atomic Read “consume”, Atomic Set “cst – consistent” for setting
This way the expenses of the atomic operation comes quicker to the code readers eye; its using the setter & getter methods. The test case doesn’t increment the int, it simply sets the counter as new value – thus the resulting numbers look different. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_consume, std::memory_order_seq_cst for setting.

8: Atomic Read “acquire”, Atomic Set “cst – consistent” for setting
This way the expenses of the atomic operation comes quicker to the code readers eye; its using the setter & getter methods. The test case doesn’t increment the int, it simply sets the counter as new value – thus the resulting numbers look different. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_acquire, std::memory_order_seq_cst for setting.

9: Atomic Read “consume”, Atomic Set “relaxed” for setting
This way the expenses of the atomic operation comes quicker to the code readers eye; its using the setter & getter methods. The test case doesn’t increment the int, it simply sets the counter as new value – thus the resulting numbers look different. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_consume, std::memory_order_relaxed for setting.

10: Atomic Read “acquire”, Atomic Set “relaxed” for setting
This way the expenses of the atomic operation comes quicker to the code readers eye; its using the setter & getter methods. The test case doesn’t increment the int, it simply sets the counter as new value – thus the resulting numbers look different. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_acquire, *std::memory_order_relaxed for setting.

11: Atomic Read “Acquire”, Atomic exchange weak for writing
This way the expenses of the atomic operation comes quicker to the readers eye; its using the setter & getter methods. This test case implements incrementing using while loops, as suggested by the documentation. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_acquire, std::memory_order_relaxed for setting.

12: Atomic Read “consume”, Atomic exchange weak for writing
This way the expenses of the atomic operation comes quicker to the readers eye; its using the setter & getter methods. This test case implements incrementing using while loops, as suggested by the documentation. Atomic Load is used to retrieve the value in the readers; It offers several heuristics; this test chooses the std::memory_order_consume, std::memory_order_relaxed for setting.

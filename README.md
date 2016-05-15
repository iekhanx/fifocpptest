                          C++ FIFO Test exercise
                          ======================

 1/ Assuming existing computer system complete GNU build system already been 
    installed, hence make file can generate binary

 2/ IF Cross compile requirement? Assuming cross compile GNU tool chain
    alread has been install

 3/ Cross compilation requirement must be set as follow
     ARCH=arm
     CROSS_COMPILE=arm-linux-gnueabihf-

 4/ IT is highly advisiable to clone the program from following link:
      
     git clone git@gitlab.com:iekhanx/fifocpptest.git

     cd fifocpptest/src

     <type> make <return>
  
     Will generate a binary file as follow:

     cpptest_x86   - for an Intel CPU
     cpptest_arm   - for ARM CPU


    Created by:
    Imran Khan on 13/05/2016 at 16:06pm
    ===================================

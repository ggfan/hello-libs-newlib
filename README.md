testing adding a new lib to hello-libs ([googlesamples/android-ndk - master-cmake branch](https://github.com/googlesamples/android-ndk/tree/master-cmake) )

**PROBLEM:**

**Scenario 1:**
distribution folder all empty; 'Rebuild project' with target_link_libraries(hello-libs log android lib_gperf lib_gmath lib_newlib) in main CMakeLists.txt
-> gperf and gmath are created, newlib is not -> error 
[Error: '/Users/.../hello-libs/distribution/newlib/lib/x86_64/libnewlib.so', needed by '/Users/.../hello-libs/app/build/intermediates/cmake/debug/obj/x86_64/libhello-libs.so', missing and no known rule to make it]

**Scenario 2:** (my workaround)
distribution folder empty; 'Rebuild project' with target_link_libraries(hello-libs log android lib_gperf lib_gmath) AND commenting out all codelines which are referring to 'newly'
-> all 3 libs (gperf, gmath, newly) are created
-> changing target_link_libraries statement back to target_link_libraries(hello-libs log android lib_gperf lib_gmath lib_newlib) AND bringing back the previously out-commented lines -> Rebuild & Run Successful -> great (even in case of changes in the newlib's source code the library is getting rebuild -> works as expected)

_short:_
builing library 'newlib' in /destination when 
  - target_link_libraries(hello-libs log android lib_gperf lib_gmath lib_newlib) DOESN'T work
  - target_link_libraries(hello-libs log android lib_gperf lib_gmath ~~lib_newlib~~)  DOES work

What's wrong?

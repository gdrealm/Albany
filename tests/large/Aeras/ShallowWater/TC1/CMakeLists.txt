 

# 1. Copy Input file from source to binary dir
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/inputT.xml
               ${CMAKE_CURRENT_BINARY_DIR}/inputT.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_homme_comp_BDF2_np4_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_homme_comp_BDF2_np4_T.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_homme_comp_BDF2_np7_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_homme_comp_BDF2_np7_T.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_homme_comp_RK3TVD_np4_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_homme_comp_RK3TVD_np4_T.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_homme_comp_RK3TVD_np7_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_homme_comp_RK3TVD_np7_T.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_homme_comp_RK3TVD_np4_hv_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_homme_comp_RK3TVD_np4_hv_T.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_homme_comp_RK3TVD_np7_hv_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_homme_comp_RK3TVD_np7_hv_T.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_explicit_slotcyl_hv_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_explicit_slotcyl_hv_T.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_explicit_slotcyl_hv_T_rk4.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_explicit_slotcyl_hv_T_rk4.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/uniform_10.g
               ${CMAKE_CURRENT_BINARY_DIR}/uniform_10.g COPYONLY)
               
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_slotcyl_explHV_nu0_BEuler_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_slotcyl_explHV_nu0_BEuler_T.xml COPYONLY)  
               
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_slotcyl_explHV_nu1e17_BEuler_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_slotcyl_explHV_nu1e17_BEuler_T.xml COPYONLY)
               
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_slotcyl_explHV_nu0_RK4_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_slotcyl_explHV_nu0_RK4_T.xml COPYONLY)    

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_slotcyl_explHV_nu1e17_RK4_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_slotcyl_explHV_nu1e17_RK4_T.xml COPYONLY)  
               
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_slotcyl_implHV_nu0_BEuler_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_slotcyl_implHV_nu0_BEuler_T.xml COPYONLY) 
               
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_slotcyl_implHV_nu1e17_BEuler_T.xml
               ${CMAKE_CURRENT_BINARY_DIR}/input_slotcyl_implHV_nu1e17_BEuler_T.xml COPYONLY)                

                            
# 2. Name the test with the directory name
get_filename_component(testName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# 3. Create the test with this name and standard executable
#add_test(Aeras_${testName}_SlotCyl_HV_Tpetra ${AlbanyT.exe} input_slotcyl_hv_T.xml)

add_test(Aeras_${testName}_SlotCyl_implicitHV_nu0_BackwardEuler ${AlbanyT.exe} input_slotcyl_implHV_nu0_BEuler_T.xml)
add_test(Aeras_${testName}_SlotCyl_implicitHV_nu1e17_BackwardEuler ${AlbanyT.exe} input_slotcyl_implHV_nu1e17_BEuler_T.xml)

add_test(Aeras_${testName}_SlotCyl_explicitHV_nu0_BackwardEuler ${AlbanyT.exe} input_slotcyl_explHV_nu0_BEuler_T.xml)
add_test(Aeras_${testName}_SlotCyl_explicitHV_nu1e17_BackwardEuler ${AlbanyT.exe} input_slotcyl_explHV_nu1e17_BEuler_T.xml)

add_test(Aeras_${testName}_SlotCyl_explicitHV_nu0_RungeKutta4 ${AlbanyT.exe} input_slotcyl_explHV_nu0_RK4_T.xml)

if (ALBANY_EPETRA)
add_test(Aeras_${testName}_SlotCyl_explicitHV_nu1e17_RungeKutta4 ${AlbanyT.exe} input_slotcyl_explHV_nu1e17_RK4_T.xml)
endif() 

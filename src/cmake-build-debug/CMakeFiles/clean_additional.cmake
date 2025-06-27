# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Tarea3_PubSubSimulator_Etapa1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Tarea3_PubSubSimulator_Etapa1_autogen.dir\\ParseCache.txt"
  "Tarea3_PubSubSimulator_Etapa1_autogen"
  )
endif()

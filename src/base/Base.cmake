# A Helper script. Include this and use the variables OPDE_BASE_INCLUDES and OPDE_SERVICE_INCLUDES instead of the great lists

SET(OPDE_BASE_INCLUDES
    ${OPDE_SOURCE_DIR}/src/compat
    ${OPDE_SOURCE_DIR}/src/base
    ${OPDE_SOURCE_DIR}/src/base/console
    ${OPDE_SOURCE_DIR}/src/base/dyntype
    ${OPDE_SOURCE_DIR}/src/base/file
    ${OPDE_SOURCE_DIR}/src/base/loaders
    ${OPDE_SOURCE_DIR}/src/base/logger
    ${OPDE_SOURCE_DIR}/src/base/servicemanager
)

# All the resulting libraries in a nice package as well
SET(OPDE_BASE_LIBRARIES
    OpdeBase
#    OpdeConsole
#    OpdeDynType
#    OpdeFile
#    OpdeManualLoaders
#    OpdeLogger
#    OpdeServiceManager
)

# For the dynamically built lib. We just glob all the subdirs.
FILE(GLOB_RECURSE OPDE_BASE_SOURCES ${OPDE_SOURCE_DIR}/src/base/*.h)
FILE(GLOB_RECURSE OPDE_BASE_HEADERS ${OPDE_SOURCE_DIR}/src/base/*.cpp)
SET(OPDE_BASE_FILES ${OPDE_BASE_HEADERS} ${OPDE_BASE_SOURCES})

# To use this, just do INCLUDE(${OPDE_SOURCE_DIR}/src/base/Base.cmake)

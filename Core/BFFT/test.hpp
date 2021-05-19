/**
* @file mymain.hpp
*
* @brief Header for the cpp main
* @author Manuel Ehrhardt
* @date 22.04.2020
*
**/

#ifndef TEST_H
#define TEST_H

typedef enum
{
   TEST_INIT,
   TEST_EXECUTE,
   TEST_ERROR,
} TEST_STATES;



#ifdef __cplusplus
extern "C" {
#endif
   void vtestCAN (void);
   void CAN1_irq_receive();

#ifdef __cplusplus
}
#endif

#endif /* INC_MYMAIN_HPP_ */

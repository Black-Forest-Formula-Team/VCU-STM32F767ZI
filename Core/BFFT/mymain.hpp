/**
* @file mymain.hpp
*
* @brief Header for the cpp main
* @author Manuel Ehrhardt
* @date 22.04.2020
*
**/

#ifndef INC_MYMAIN_HPP_
#define INC_MYMAIN_HPP_

#ifdef __cplusplus
extern "C" {
#endif
typedef enum
{
	TEST_INIT,
	TEST_EXECUTE,
	TEST_ERROR,
} TEST_STATES;
void cppmain (void);
void CAN1_irq_receive();

#ifdef __cplusplus
}
#endif

#endif /* INC_MYMAIN_HPP_ */

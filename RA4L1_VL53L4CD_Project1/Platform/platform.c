/**
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "platform.h"
#include "r_transfer_api.h"
#include "r_iic_master.h"

extern iic_master_instance_ctrl_t g_i2c_master0_ctrl;
extern uint32_t  timeout_ms;
extern  i2c_master_event_t i2c_event;

uint8_t VL53L4CD_RdDWord(Dev_t dev, uint16_t RegisterAdress, uint32_t* value)
{
    uint8_t status = 255;

    /* To be filled by customer. Return 0 if OK */
    /* Warning : For big endian platforms, fields 'RegisterAdress' and 'value' need to be swapped. */

    uint8_t data_write[2];
    uint8_t data_read[4];

    data_write[0] = (RegisterAdress >> 8) & 0xFF;
    data_write[1] = RegisterAdress & 0xFF;

    //  status = HAL_I2C_Master_Transmit(&hi2c1, dev, data_write, 2, 100);

    status = R_IIC_MASTER_Write(&g_i2c_master0_ctrl, data_write, 2, true);
    assert(FSP_SUCCESS == status);
    /* Since there is nothing else to do, block until Callback triggers*/
    //while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms)
    while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms > 0)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }
    /* Read data back from the I2C slave */
    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;

    //  status = HAL_I2C_Master_Receive(&hi2c1, dev, data_read, 4, 100);
    status = R_IIC_MASTER_Read(&g_i2c_master0_ctrl, data_read, 4, true);
    assert(FSP_SUCCESS == status);
    while ((I2C_MASTER_EVENT_RX_COMPLETE != i2c_event) && timeout_ms)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }

    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;

    *value = ((data_read[0] << 24) | (data_read[1] << 16) |
        (data_read[2] << 8) | (data_read[3]));
    return status;
}

uint8_t VL53L4CD_RdWord(Dev_t dev, uint16_t RegisterAdress, uint16_t* value)
{
    uint8_t status = 255;

    /* To be filled by customer. Return 0 if OK */
    /* Warning : For big endian platforms, fields 'RegisterAdress' and 'value' need to be swapped. */
    uint8_t data_write[2];
    uint8_t data_read[2];

    data_write[0] = (RegisterAdress >> 8) & 0xFF;
    data_write[1] = RegisterAdress & 0xFF;
    //  status = HAL_I2C_Master_Transmit(&hi2c1, dev, data_write, 2, 100);

    status = R_IIC_MASTER_Write(&g_i2c_master0_ctrl, data_write, 2, true);
    assert(FSP_SUCCESS == status);
    /* Since there is nothing else to do, block until Callback triggers*/
    //while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms)
    while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms > 0)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }
    /* Read data back from the I2C slave */
    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;


    //  status = HAL_I2C_Master_Receive(&hi2c1, dev, data_read, 2, 100);

    status = R_IIC_MASTER_Read(&g_i2c_master0_ctrl, data_read, 2, true);
    assert(FSP_SUCCESS == status);
    while ((I2C_MASTER_EVENT_RX_COMPLETE != i2c_event) && timeout_ms)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }

    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;

    *value = (data_read[0] << 8) | (data_read[1]);


    return status;
}

uint8_t VL53L4CD_RdByte(Dev_t dev, uint16_t RegisterAdress, uint8_t* value)
{
    uint8_t status = 255;

    /* To be filled by customer. Return 0 if OK */
    /* Warning : For big endian platforms, fields 'RegisterAdress' and 'value' need to be swapped. */
    uint8_t data_write[2];
    uint8_t data_read[1];

    data_write[0] = (RegisterAdress >> 8) & 0xFF;
    data_write[1] = RegisterAdress & 0xFF;
    //  status = HAL_I2C_Master_Transmit(&hi2c1, dev, data_write, 2, 100);

    status = R_IIC_MASTER_Write(&g_i2c_master0_ctrl, data_write, 2, true);
    assert(FSP_SUCCESS == status);
    /* Since there is nothing else to do, block until Callback triggers*/
    //while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms)
    while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms > 0)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }
    /* Read data back from the I2C slave */
    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;
    //  status = HAL_I2C_Master_Receive(&hi2c1, dev, data_read, 1, 100);

    status = R_IIC_MASTER_Read(&g_i2c_master0_ctrl, data_read, 1, true);
    assert(FSP_SUCCESS == status);
    while ((I2C_MASTER_EVENT_RX_COMPLETE != i2c_event) && timeout_ms)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }

    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;


    *value = data_read[0];




    return status;
}

uint8_t VL53L4CD_WrByte(Dev_t dev, uint16_t RegisterAdress, uint8_t value)
{
    uint8_t status = 255;

    /* To be filled by customer. Return 0 if OK */
    /* Warning : For big endian platforms, fields 'RegisterAdress' and 'value' need to be swapped. */

    uint8_t data_write[3];

    data_write[0] = (RegisterAdress >> 8) & 0xFF;
    data_write[1] = RegisterAdress & 0xFF;
    data_write[2] = value & 0xFF;
    //  status = HAL_I2C_Master_Transmit(&hi2c1, dev, data_write, 3, 100);

    status = R_IIC_MASTER_Write(&g_i2c_master0_ctrl, data_write, 3, true);
    assert(FSP_SUCCESS == status);
    /* Since there is nothing else to do, block until Callback triggers*/
    //while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms)
    while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms > 0)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }
    /* Read data back from the I2C slave */
    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;

    return status;
}

uint8_t VL53L4CD_WrWord(Dev_t dev, uint16_t RegisterAdress, uint16_t value)
{
    uint8_t status = 255;

    /* To be filled by customer. Return 0 if OK */
    /* Warning : For big endian platforms, fields 'RegisterAdress' and 'value' need to be swapped. */

    uint8_t data_write[4];
    data_write[0] = (RegisterAdress >> 8) & 0xFF;
    data_write[1] = RegisterAdress & 0xFF;
    data_write[2] = (value >> 8) & 0xFF;
    data_write[3] = value & 0xFF;
    //  status = HAL_I2C_Master_Transmit(&hi2c1, dev, data_write, 4, 100);

    status = R_IIC_MASTER_Write(&g_i2c_master0_ctrl, data_write, 4, true);
    assert(FSP_SUCCESS == status);
    while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }

    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;


    return status;
}

uint8_t VL53L4CD_WrDWord(Dev_t dev, uint16_t RegisterAdress, uint32_t value)
{
    uint8_t status = 255;

    /* To be filled by customer. Return 0 if OK */
    /* Warning : For big endian platforms, fields 'RegisterAdress' and 'value' need to be swapped. */


    uint8_t data_write[6];

    data_write[0] = (RegisterAdress >> 8) & 0xFF;
    data_write[1] = RegisterAdress & 0xFF;
    data_write[2] = (value >> 24) & 0xFF;
    data_write[3] = (value >> 16) & 0xFF;
    data_write[4] = (value >> 8) & 0xFF;
    data_write[5] = value & 0xFF;
    //  status = HAL_I2C_Master_Transmit(&hi2c1, dev, data_write, 6, 100);

    status = R_IIC_MASTER_Write(&g_i2c_master0_ctrl, data_write, 6, true);
    assert(FSP_SUCCESS == status);
    /* Since there is nothing else to do, block until Callback triggers*/
    //while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms)
    while ((I2C_MASTER_EVENT_TX_COMPLETE != i2c_event) && timeout_ms > 0)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == i2c_event)
    {
        __BKPT(0);
    }
    /* Read data back from the I2C slave */
    i2c_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = 1000000;


    return status;
}

uint8_t VL53L4CD_WaitMs(Dev_t dev, uint32_t TimeMs)
{
    uint8_t status = 255;
    /* To be filled by customer */

    R_BSP_SoftwareDelay(TimeMs, BSP_DELAY_UNITS_MILLISECONDS);

    return status;
}

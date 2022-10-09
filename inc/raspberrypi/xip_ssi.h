/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file XIP SSI peripheral definitions */
#ifndef XIP_SSH_H
#define XIP_SSH_H

typedef volatile struct {
  uint32_t CTRL0;          /*!< Control register 0*/
  uint32_t CTRL1;          /*!< Master control register 1 */
  uint32_t SSIENR;         /*!< SSI Enable */
  uint32_t MWCR;           /*!< Microwire Control*/
  uint32_t SER;            /*!< Slave enable*/
  uint32_t BAUDR;          /*!< Baud rate */
  uint32_t TXFTLR;         /*!< TX FIFO threshold level */
  uint32_t RXFTLR;         /*!< RX FIFO threshold level */
  uint32_t SR;             /*!< Status register */
  uint32_t IMR;            /*!< Interrupt mask */
  uint32_t ISR;            /*!< Interrupt status */
  uint32_t RISR;           /*!< Raw interrupt status */
  uint32_t TXOICR;         /*!< TX FIFO overflow interrupt clear */
  uint32_t RXOICR;         /*!< RX FIFO overflow interrupt clear */
  uint32_t RXUICR;         /*!< RX FIFO underflow interrupt clear */
  uint32_t MSTICR;         /*!< Multi-master interrupt clear */
  uint32_t ICR;            /*!< interrupt clear */
  uint32_t DMACR;          /*!< DMA control */
  uint32_t DMATDLR;        /*!< DMA TX data level */
  uint32_t DMARDLR;        /*!< DMA RX data level */
  uint32_t IDR;            /*!< Identification register */
  uint32_t SSI_VERSION_ID; /*!< Version ID */
  uint32_t DR[36];         /*!< Dataregister */
  uint32_t RX_SAMPLE_DLY;  /*!< RX sample delay */
  uint32_t SPI_CTRLR0;     /*!< SPI control */
  uint32_t TXD_DRIVE_EDGE; /*!< TX drive edge */
} XIP_SSH_Type;

#endif
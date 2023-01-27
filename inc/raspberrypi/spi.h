/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file SPI peripheral definitions */
#ifndef SPI_H
#define SPI_H

typedef volatile struct {
  uint32_t SSPCR0;   /**< Control register 0 */
  uint32_t SSPCR1;   /**< Control register 1 */
  uint32_t SSPDR;    /**< Data register */
  uint32_t SSPSR;    /**< Status register */
  uint32_t SSPCPSR;  /**< Clock prescale register */
  uint32_t SSPIMSC;  /**< Interrupt mask set or clear register */
  uint32_t SSPRIS;   /**< Raw interrupt status register */
  uint32_t SSPMIS;   /**< Masked interrupt status register */
  uint32_t SSPICR;   /**< Interrupt clear register */
  uint32_t SSPDMACR; /**< DMA control register*/
  uint32_t reserved0[1006];
  uint32_t SSPPERIPID0; /**< Peripheral identification register 0 */
  uint32_t SSPPERIPID1; /**< Peripheral identification register 1 */
  uint32_t SSPPERIPID2; /**< Peripheral identification register 2 */
  uint32_t SSPPERIPID3; /**< Peripheral identification register 3 */
  uint32_t SSPPCELLID0; /**< PrimeCell identification register 0 */
  uint32_t SSPPCELLID1; /**< PrimeCell identification register 1 */
  uint32_t SSPPCELLID2; /**< PrimeCell identification register 2 */
  uint32_t SSPPCELLID3; /**< PrimeCell identification register 3 */
} SPI_Type;

#endif
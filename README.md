# Sample Zephyr Driver

This repository is a template that can be used to create sensor drivers for <a href="https://docs.zephyrproject.org/latest/index.html">Zephyr RTOS</a>. It contains all the functions and definitions that a working driver needs.

This sample has been designed to work with Nordic's <a href="https://www.nordicsemi.com/Products/Development-software/nRF-Connect-SDK">nRF Connect SDK</a>.

To include in a project, add the following lines to your west manifest

    - name: sample
      path: modules/sample
      revision: main
      url: https://github.com/niallphealy/sample_zephyr_driver.git

The run `west update` in an nRF Connect terminal.

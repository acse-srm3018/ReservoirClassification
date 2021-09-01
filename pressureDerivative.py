"""Module for take a pressure derivative."""

import numpy as np
import pandas as pd


def pressureder(press_time, initial_pressure):
    """
    Take derivative from pressure data.

    Parameters:
    ----------
    press_time : Ndarray
        The pressure versus time data
    initial_pressure : float

    Returns:
    ----------
    loaded_data : ndarray
        The data which was loaded
    """
    time = press_time[:, 1]
    pressure = press_time[:, 2]
    log_time = np.log(time)
    delta_p = initial_pressure-pressure
    derivation = []
    time_plot = []
    log_time_plot = []

    for j in range(len(time)-2):
        der = (((delta_p[j+1]-delta_p[j]) * (log_time[j+2]-log_time[j+1]) /
                (log_time[j+1]-log_time[j])) + ((delta_p[j+2]-delta_p[j+1])
                  *(log_time[j+1]-log_time[j]) /
                (log_time[j+2]-log_time[j+1])))/(log_time[j+2]-log_time[j])
        log_t_plot = log_time[j+2]
        t_plot = time[j+2]
        derivation.append(der)
        time_plot.append(t_plot)
        log_time_plot.append(log_t_plot)

    derivation = np.array(derivation)
    return derivation

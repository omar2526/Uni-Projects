# -*- coding: utf-8 -*-
"""Calculus 2 project group 6.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1ZTmLJdVxlui7rtotfkZvnX3kB3Zk5iZ4
"""

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

# mount the drive content to google colab
from google.colab import drive
drive.mount('/content/drive')

df = pd.read_csv("/content/drive/MyDrive/Spring 2024 - Math with Applications/MTH102 Calculus II/Project/real_estate.csv")
df

# input
## x_0. integer
## x_1. integer
def predictValue_hourInflation(x0, x1):
  return (4*x0) + (101*x1) + 45

predictValue_hourInflation(20, 0.5)

df["Y house price of unit area"]

df["Y house price of unit area"].to_numpy()

df["X2 house age"]

df["X2 house age"].to_numpy()

tem = df["X2 house age"].to_numpy()

tem

predictValue_hourInflation(tem, tem)

error=abs(df['X2 house age']-tem)

error

x2=df["X2 house age"]

import seaborn as sns
import matplotlib.pyplot as plt

def scatterFeatureError(X, Y, Z):
  cmap = sns.cubehelix_palette(as_cmap=True)
  f, ax = plt.subplots()
  points = ax.scatter(X, Y, c=Z, s=50, cmap=cmap)
  f.colorbar(points)

# visualize
scatterFeatureError( x2,tem, error)

# Objective function
def f(w):
          return((w[0]*2)+(3*w[1])+55)
# Function to compute the gradient
def grad(w):
           return (np.array([2,0])*w)+np.array([0,3])

# @title
# Hidden
###

# Helper function to annotate a single point
def annotate_pt(text, xy, xytext, color):
  plt.plot(xy[0],xy[1],marker='P',markersize=10,c=color)
  plt.annotate(text,xy=xy,xytext=xytext,
                # color=color,
                arrowprops=dict(arrowstyle="->",
                color = color,
                connectionstyle='arc3'))


# Plot the function
# Pts are 2D points and f_val is the corresponding function value
def function_plot(pts, f_val, vmin=None, vmax=None):
  if vmin == None:
    vmin = min(f_val)
  if vmax == None:
    vmax = max(f_val)

  f_plot = plt.scatter(pts[:,0],pts[:,1],
                        c=f_val,vmin=vmin,vmax=vmax,
                        cmap='RdBu_r')
  plt.colorbar(f_plot)
  # Show the optimal point
  #annotate_pt('global minimum',(0,0),(-5,-7),'yellow')


def visualize_fw(f, x_ran, y_ran):
  xcoord = np.linspace(x_ran[0], x_ran[1], 50)
  ycoord = np.linspace(y_ran[0], y_ran[1], 50)
  w1, w2 = np.meshgrid(xcoord, ycoord)
  pts = np.vstack( (w1.flatten(), w2.flatten()) )

  # All 2D points on the grid
  pts = pts.transpose()

  # Function value at each point
  f_vals = np.apply_along_axis( f, axis=1, arr=pts )

  # function is x^2
  #f_vals = np.sum(pts*pts, axis=1)
  #return f_vals
  function_plot(pts, f_vals)
  #plt.title('Objective Function Shown in Color')
  plt.show()
  return pts, f_vals

# plots function values by color bar, on [-10, 10] for x axis and [-10, 10] for y axis
# returns points and function values
pts, f_vals = visualize_fw(f, [-10, 10], [-10, 10])

def df(w):
   return (np.array([2,0])*w)+np.array([0,3])

w=np.array([2,6])
df(w)

def f(w):
    return((w[0]*2)+(3*w[1])+55)

w=np.array([2,6])
f(w)

def visualize_learning(pts, f_vals, w_history):

  # Make the function plot
  function_plot(pts, f_vals)

  # Plot the history
  plt.plot(w_history[:,0],w_history[:,1],marker='o',c='magenta')

  # Annotate the point found at last iteration
  annotate_pt('Last Position',
              (w_history[-1,0],w_history[-1,1]),
              (-1,7),'green')
  iter = w_history.shape[0]
  for w,i in zip(w_history,range(iter-1)):
    # Annotate with arrows to show history
    plt.annotate("",
                xy=w, xycoords='data',
                xytext=w_history[i+1,:], textcoords='data',
                arrowprops=dict(arrowstyle='<-',
                        connectionstyle='angle3'))

# input: max_iterations  Iterations number
#        threshold       Stepping threshold
#        w_init          Initial position
#        obj_func        Objective function
#        grad_func       Gradient function
#        learning_rate   Learning rate
#        momentum        Momentum
# output:
def gradient_descent(max_iterations, threshold, w_init,
                     obj_func, grad_func,
                     learning_rate = 0.05, momentum = 0.8):

  # initialize position at w_init
  w = w_init
  # history of positions is only w
  w_history = w
  # history of objective function positions is only obj_func(w)
  f_history = obj_func(w)
  # initialize learned step to zero
  delta_w = np.zeros(w.shape)
  # initialize iteration counter
  iter_cou = 0
  # the difference between last two successive values of the objective function
  diff = 1.0e10

  # learn until maximum iterations is passed, or
  # the difference between objective function values is below the threshold
  while  iter_cou < max_iterations and diff > threshold:

    # compute the difference between current position and new learned position by the gradient
    # momentum to step by previous gradients, even when current gradient is low
    delta_w = ( -learning_rate * grad_func(w) ) + (momentum * delta_w)
    # step to the new position by the computed difference, i.e delta
    w = w + delta_w

    # store the history of w (positions) and f (objective function values)
    w_history = np.vstack( (w_history, w) )
    f_history = np.vstack( (f_history, obj_func(w)) )

    # increment iteration number
    iter_cou += 1
    # compute the diff between last two successive values of the objective function
    diff = np.absolute( f_history[-1] - f_history[-2])

  return w_history, f_history

def solve_fw(w_init, learning_rate, momentum):

  # compute gradient sequence
  # positions, and function values
  w_history, f_history = gradient_descent(5, -1, w_init, f, grad, learning_rate, momentum)

  # Plot
  visualize_learning(pts, f_vals, w_history)
  plt.text(-5, 12,'Learning Rate = '+str(learning_rate), fontsize=13)
  plt.text(-4, -14,'momentum = ' + str(momentum), fontsize=13)
  plt.show()

  return w_history[-1], f_history[-1]

# learning parameters
rand = np.random.RandomState(19)
w_init = rand.uniform(-10, 10, 2)
learning_rate = 0.5
momentum = 0.5

# plot learning steps
# get optimal position and optimal function value
opt_w, opt_f = solve_fw(w_init, learning_rate, momentum)
# 3.1 Linear Regression

Linear Regression is a **supervised learning algorithm** used for **regression problems**, where the target variable is **real-valued**. The model learns a **linear relationship** between input features and the target.

---

## 3.1.1 Problem Statement

### Dataset Definition

We are given a labeled dataset:

{ (x_i, y_i) } for i = 1..N

Where:

- **N**: number of training examples  
- **x_i**: D-dimensional feature vector of example i (x_i ∈ R^D)  
- **y_i**: real-valued target (y_i ∈ R)  
- Each feature x_i(j) is also a real number  

---

### Model Definition

The linear regression model is defined as:

f(x) = wᵀx + b

Where:

- **w**: weight vector in R^D (model parameters)  
- **b**: bias term (real number)  

The notation f(x) indicates that the model is **parameterized** by w and b.

---

### Prediction

For a new input example x, the predicted target is:

y_hat = f(x)

Different parameter values (w, b) produce **different models** and therefore **different predictions**.

The learning objective is to find the **optimal parameters**:

(w*, b*)

that yield the most accurate predictions.

---

### Geometric Interpretation

- For **D = 1** → the model is a **line**
- For **D = 2** → the model is a **plane**
- For **D > 2** → the model is a **hyperplane**

The regression hyperplane is chosen to be **as close as possible to all training points**.

---

### Comparison with SVM

| Linear Regression                       | Support Vector Machine      |
|----------------------------------------|-----------------------------|
| Predicts real values                   | Predicts class labels       |
| Hyperplane minimizes distance to points| Hyperplane maximizes margin |
| No sign function                       | Uses sign operator          |

Although the mathematical form is similar, the **objective** is fundamentally different.

---

## 3.1.2 Solution

### Objective Function

To fit the model, we minimize the **average squared error**:

J(w, b) = (1 / N) * sum_{i=1..N} ( f(x_i) - y_i )²

---

### Terminology Clarification

#### Loss Function

- Measures error on **one example**
- For linear regression:

l_i = ( f(x_i) - y_i )²

---

#### Cost Function

- Average loss over the dataset
- Also called **empirical risk**

J(w, b) = (1 / N) * sum_{i=1..N} l_i

---

#### Objective Function

- General term for the function we **minimize or maximize**
- In linear regression, the objective = cost function

---

## Why Squared Error Loss?

### Mathematical Reasons

- Squared loss is **smooth** and **differentiable everywhere**
- Enables use of **linear algebra**
- Allows **closed-form solutions**

Absolute error:

- Not differentiable at 0
- Makes optimization harder

Higher powers (cube, fourth power):

- Valid but derivatives become more complex

---

### Historical Note

Adrien-Marie Legendre (1705) introduced the **sum of squared errors**, noting that squaring errors before summation is mathematically convenient.

---

### Intuition

- Squaring **penalizes large errors more strongly**
- Encourages the model to avoid large deviations

---

## Model Design Choices in ML

A machine learning algorithm is defined by:

1. **Model form** (linear, polynomial, neural network)
2. **Loss function** (squared error, absolute error, logistic loss)
3. **Optimization method** (closed-form, gradient descent)

Changing any of these leads to a **different algorithm**.

---

## Overfitting Considerations

### Overfitting

A model overfits when:

- It performs very well on training data
- Performs poorly on unseen data

### Linear Regression Advantage

- Low model complexity
- Few parameters
- Rarely overfits

### Example

- Polynomial regression (degree 10) fits training data almost perfectly
- Produces large errors on new data

---

## Why Do We Care About the Gradient?

- The cost function is **convex**
- The minimum occurs where the **gradient equals zero**

Gradient condition:

grad J(w, b) = 0

This leads to a system of equations whose solution gives:

(w*, b*)

---

## Key Takeaways

- Linear regression models a **linear relationship** between features and target
- Training consists of minimizing **empirical risk**
- Squared loss enables smooth optimization and closed-form solutions
- Simplicity helps prevent overfitting

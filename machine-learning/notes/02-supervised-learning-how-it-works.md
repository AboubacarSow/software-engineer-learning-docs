# 1.3 How Supervised Learning Works

This section provides a high-level overview of the supervised learning pipeline, using **Support Vector Machines (SVM)** as a concrete example.

---

## Overview

Supervised learning builds a model from a dataset composed of **(input, output)** pairs.  
The objective is to learn a function that maps inputs to correct outputs and generalizes well to unseen data.

---

## 1. Data Collection

- Dataset consists of labeled examples:
  - `(x_i, y_i)`
- **Inputs (`x`)**: emails, images, sensor readings, text, etc.
- **Outputs (`y`)**:
  - Class labels (e.g. `spam`, `not_spam`)
  - Numeric values
  - Structured outputs (vectors, sequences)

**Example**  
Spam detection with 10,000 emails labeled as `spam` or `not_spam`.

---

## 2. Feature Extraction

Real-world data must be converted into **machine-readable feature vectors**.

### Bag of Words (Text Example)

- Build a dictionary of words (e.g. 20,000 words).
- Each email is represented as a binary vector:
  - `1` → word appears
  - `0` → word does not appear

Result:
- 10,000 emails → 10,000 vectors
- Each vector has **20,000 dimensions**

---

## 3. Label Encoding

Some learning algorithms require **numeric labels**.

For SVM:
- Positive class (`spam`) → **+1**
- Negative class (`not_spam`) → **-1**

---

## 4. Model Representation (SVM)

- Each feature vector is a point in a **D-dimensional space**.
- SVM finds a **decision boundary** (hyperplane) separating the classes.

### Hyperplane Equation

`w · x - b = 0`

- `w`: weight vector (same dimension as `x`)
- `b`: bias term

---

## 5. Prediction Rule

Predicted label for an input vector `x`:

`y = sign(w · x - b)`

- `+1` → positive class
- `-1` → negative class

---

## 6. Training Objective

The goal of training is to find optimal parameters:

- `w*`, `b*`

### Constraints

For each training example `(x_i, y_i)`:

- If `y_i = +1`:
  - `w · x_i - b ≥ 1`
- If `y_i = -1`:
  - `w · x_i - b ≤ -1`

Compact form:

`y_i (w · x_i - b) ≥ 1`

---

## 7. Margin Maximization

- **Margin** = distance between closest points of both classes.
- SVM maximizes margin by minimizing the norm of `w`:

`min ||w||`

Distance between margin boundaries:

`2 / ||w||`

### Why It Matters

- Larger margin → better **generalization**
- Reduces sensitivity to noise and outliers

---

## 8. Optimization Problem

Final optimization formulation:

`min ||w||  subject to  y_i (w · x_i - b) ≥ 1`

- Solving this yields the **statistical model**
- The process is called **training**

---

## 9. Decision Boundaries

- Every classification algorithm defines a decision boundary.
- Boundaries can be:
  - Linear (straight line / plane)
  - Non-linear (via kernels)
- Shape of the boundary determines model accuracy.

---

## 10. Practical Considerations

Beyond accuracy, real-world systems care about:
- Training time
- Prediction latency
- Resource usage

Sometimes:

> A faster, less accurate model is preferable to a slow, highly accurate one.

---

## Key Takeaways

- Supervised learning relies on labeled data.
- Feature engineering is crucial.
- SVM learns by:
  - Separating classes
  - Maximizing margin
- Decision boundaries define how models classify data.
- Generalization improves with larger datasets and larger margins.

---

## Further Reading

- **Chapter 3**: Support Vector Machines (detailed)
- **PAC Learning Theory**: Relationship between error, data size, model complexity, and learnability

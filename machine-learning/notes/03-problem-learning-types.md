# 2.6 Classification vs. Regression

Machine learning problems can be broadly categorized based on the **type of output** they predict.

---

## Classification

**Classification** is the task of assigning a **discrete label** to an unlabeled example.

* Output space is **finite and discrete** set:
```
    y ∈ {c1, c2, ..., cK}
```

### Examples

* Spam detection (`spam` / `not_spam`)
* Medical diagnosis (`sick` / `healthy`)
* Digit recognition (`0–9`)

### Binary vs. Multiclass

* **Binary classification**: two classes
 ```
y ∈ {0, 1}  or  {-1, +1}
```

**Multiclass classification:**

```
y ∈ {1, 2, ..., K},  K ≥ 3
```

Some algorithms are inherently binary and require strategies (e.g. one-vs-rest) to handle multiclass problems.

### Model Output

A classification model may output:

* A **label directly**
* A **score or probability**, e.g.

```
P(y = spam | x) = 0.92
```

The probability represents confidence; the final label is derived from it.

---

## Regression

**Regression** is the task of predicting a **continuous numerical value**.

* Output space is continuous:
```
y ∈ ℝ
```

### Examples

* House price prediction
* Temperature estimation
* Signal strength prediction

There are no classes or decision boundaries — only numerical targets.

---

## Unified View

Both classification and regression learn a function:

```
ŷ = fθ(x)
```

The difference lies in:

* The **type of output**
* The **loss function** used to measure error

---

# 2.7 Model-Based vs. Instance-Based Learning

This distinction describes **where the learned knowledge is stored**.

---

## Model-Based Learning

* Learns parameters (\theta) from training data
* Training data can be discarded after training
* Predictions use only the learned model

### Examples

* Linear / Logistic Regression
* Support Vector Machines (SVM)
* Neural Networks

**Characteristics**

* Training: expensive
* Inference: fast
* Memory: fixed

> Training compresses data into parameters.

---

## Instance-Based Learning

* No explicit training phase
* Entire dataset is retained
* Predictions are made by comparing new inputs to stored examples

### Example

* k-Nearest Neighbors (kNN)

**Characteristics**

* Training: trivial
* Inference: expensive
* Memory: high

> The dataset itself is the model.

---

## Key Insight

* Model-based methods capture **global structure**
* Instance-based methods rely on **local similarity**

---

# 2.8 Shallow vs. Deep Learning

This distinction is about **how features are obtained**, not about “AI complexity”.

---

## Shallow Learning

* Model parameters are learned **directly from input features**
* Features are usually **engineered by humans**

Example:

```
y = w · x + b
```

Most classical ML algorithms are shallow.

---

## Deep Learning

* Model learns **multiple layers of representations**
* Most parameters are learned from **intermediate features**, not raw input

Conceptually:
```
x → h1 → h2 → ... → y
```

Each layer extracts higher-level structure from the previous one.

---

## Summary Table

| Concept                       | Key Question               | Answer             |
| ----------------------------- | -------------------------- | ------------------ |
| Classification vs Regression  | What is predicted?         | Label vs Number    |
| Model-based vs Instance-based | Where is knowledge stored? | Parameters vs Data |
| Shallow vs Deep               | Who builds features?       | Human vs Model     |

---

**Status:** Foundations ready
**Next step:** Fundamental algorithms (Linear Regression, Logistic Regression, SVM)

---



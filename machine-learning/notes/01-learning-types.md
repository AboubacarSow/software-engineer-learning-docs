# Types of Learning in Machine Learning

Machine learning problems are commonly categorized according to **the kind of feedback available to the learning algorithm**. This categorization is fundamental because it determines how models are trained, what assumptions are made, and what kinds of problems can be solved.

At a high level, learning can be:

* **Supervised**
* **Unsupervised**
* **Semi-supervised**
* **Reinforcement-based**

Each paradigm differs in how data is structured and how learning signals are obtained.

---

## 1. Supervised Learning

### Definition

In **supervised learning**, the dataset consists of **labeled examples**:

```
{ (x₁, y₁), (x₂, y₂), …, (xₙ, yₙ) }
```

Each example contains:

* **Feature vector** `xᵢ`
* **Label** `yᵢ`

The term *supervised* refers to the fact that the algorithm is provided with the correct answers during training.

---

### Feature Vectors and Features

A **feature vector** is an ordered collection of values:

```
x = [x(1), x(2), …, x(D)]
```

Each component `x(j)` is called a **feature** and represents one measurable property of the example.

Important constraints:

* Each feature position has a **fixed semantic meaning**
* Feature `x(j)` must represent the same concept across all examples

Example (person dataset):

* `x(1)` → height (cm)
* `x(2)` → weight (kg)
* `x(3)` → gender

This consistency is critical for learning meaningful patterns.

---

### Labels

The label `y` can take different forms:

* a **class label** (classification)
* a **real number** (regression)
* more complex structures (vectors, trees, graphs)

In most introductory settings, labels are:

* categorical values, or
* real-valued numbers

Example:

* Spam detection → `{spam, not_spam}`
* Disease risk → probability or score

---

### Objective of Supervised Learning

The goal is to learn a **model** (function) `f` such that:

```
f(x) ≈ y
```

The learned model should:

* perform well on training data
* generalize to unseen examples drawn from the same distribution

---

### Common Supervised Problem Types

* **Classification**: predict a class
* **Regression**: predict a numeric value

These two problem types cover the majority of supervised learning applications.

---

## 2. Unsupervised Learning

### Definition

In **unsupervised learning**, the dataset consists only of **unlabeled examples**:

```
{ x₁, x₂, …, xₙ }
```

There is no explicit notion of a correct output.

---

### Objective of Unsupervised Learning

The goal is to learn a model that:

* discovers **structure** in the data
* transforms data into a more useful representation
* summarizes or compresses information

The model may output:

* another feature vector
* a scalar value
* a structural assignment

---

### Common Unsupervised Tasks

* **Clustering**: assign each example to a group
* **Dimensionality reduction**: map data to fewer features
* **Outlier detection**: measure deviation from typical behavior

Unsupervised learning is closer to **representation learning and compression** than to prediction.

---

## 3. Semi-Supervised Learning

### Definition

In **semi-supervised learning**, the dataset contains:

* a **small set of labeled examples**
* a **large set of unlabeled examples**

This reflects many real-world scenarios where labeling is expensive but raw data is abundant.

---

### Objective of Semi-Supervised Learning

The goal is the same as in supervised learning:

```
f(x) ≈ y
```

However, the algorithm also leverages **unlabeled data** to:

* learn better representations
* capture the underlying data structure
* reduce overfitting when labels are scarce

The hope is that unlabeled data helps produce a **better model** than supervised learning alone.

---

### Typical Use Cases

* image and video recognition
* speech and text processing
* large-scale industrial ML systems

Semi-supervised learning sits conceptually **between supervised and unsupervised learning**.

---

## 4. Reinforcement Learning

### Definition

**Reinforcement learning (RL)** studies learning systems that:

* interact with an **environment**
* observe the **state** of the environment as a feature vector
* take **actions** that affect future states
* receive **rewards** as feedback

---

### Core Components

A reinforcement learning problem consists of:

* **State**: representation of the environment
* **Action**: decision taken by the agent
* **Reward**: scalar feedback signal
* **Policy**: function mapping states to actions

---

### Objective of Reinforcement Learning

The goal is to learn a **policy** `f` that:

```
f(state) → action
```

such that the **expected long-term reward** is maximized.

Unlike supervised learning:

* feedback is delayed
* actions influence future inputs
* decisions are sequential and interdependent

---

### Problem Characteristics

Reinforcement learning is suitable for problems where:

* decisions must be made over time
* short-term actions affect long-term outcomes

Examples:

* game playing
* robotics
* resource management
* logistics

---

## 5. Summary Perspective

The four learning paradigms differ primarily in **how learning signals are obtained**:

| Learning Type   | Labels             | Feedback Style | Typical Goal        |
| --------------- | ------------------ | -------------- | ------------------- |
| Supervised      | Yes                | Immediate      | Prediction          |
| Unsupervised    | No                 | None           | Structure discovery |
| Semi-supervised | Partial            | Mixed          | Improved prediction |
| Reinforcement   | No explicit labels | Delayed reward | Optimal control     |

Understanding these distinctions is essential before studying specific algorithms, loss functions, or optimization techniques.

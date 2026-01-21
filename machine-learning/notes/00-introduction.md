# Machine Learning — Foundations & Mental Models

## 1. What Machine Learning Really Is (and What It Is Not)

Let’s start with an uncomfortable but important truth:

> **Machines do not learn in the human or biological sense.**

What we call *machine learning* is the process of **finding a mathematical function** (or model) that maps inputs to outputs based on examples, such that it performs well not only on known examples but also on *new, unseen* ones — **provided they come from a similar statistical distribution**.

In other words, a machine learning system:

* does **not** understand
* does **not** reason like humans
* does **not** generalize robustly outside its training assumptions

A small, unexpected change in the input (rotation, noise, distribution shift) can cause a trained model to fail completely — something humans are usually very robust to.

So why call it *learning*?

* The term was coined in **1959 by Arthur Samuel (IBM)**
* It was largely a **marketing and conceptual analogy**, not a literal description
* Just like *artificial intelligence* is not intelligence, *machine learning* is not learning

Despite this, the term is now universally accepted and refers to:

> **The science and engineering of building systems that improve their performance at a task through data, rather than explicit programming.**

---

## 2. Machine Learning vs Classical Programming

### Classical Programming

In classical software development, the programmer explicitly defines the rules:

```
Rules + Data  →  Output
```

Example:

* If temperature > 38°C → fever
* If email contains "FREE MONEY" → spam

This approach works well when:

* rules are clear
* edge cases are limited
* the environment is stable

### Machine Learning

In machine learning, we invert the process:

```
Data + Algorithm  →  Rules (Model)
```

The system *infers* the rules statistically from examples.

Example:

* Thousands of labeled emails → learn what “spam” looks like
* Medical records → learn risk patterns

Machine learning is therefore useful when:

* rules are unknown or too complex
* data is abundant
* the problem involves uncertainty

---

## 3. A Practical Definition of Machine Learning

A concise and engineering-oriented definition:

> **Machine learning is the process of solving a practical problem by:**
>
> 1. **Gathering a dataset** of examples
> 2. **Algorithmically building a statistical model** from that dataset
> 3. **Using that model** to make predictions or decisions

The model is essentially a **compressed representation of the dataset** that captures patterns and regularities.

---

## 4. The Building Blocks of a Machine Learning Problem

Every well-defined machine learning problem contains the following components:

### 4.1 Dataset

* A collection of examples
* Each example is represented as a **feature vector**
* Think of it as **rows in a table**, where columns are features

Example:

| Height | Weight | Age | Gender |
| ------ | ------ | --- | ------ |

Consistency is critical:

* Feature *j* must always represent the same concept

---

### 4.2 Model

* A mathematical function `f(x)`
* Approximates the unknown process that generated the data
* Chosen from a hypothesis space (linear models, trees, neural networks, etc.)

---

### 4.3 Objective / Performance Measure

A way to evaluate how good the model is:

* classification accuracy
* mean squared error
* likelihood
* reward

Without a metric, learning is undefined.

---

### 4.4 Training Experience

The information the model learns from:

* labeled data
* unlabeled data
* interactions with an environment

Tom Mitchell formalizes this with:

> A program learns from **experience E**, with respect to **task T** and **performance measure P**, if its performance at T improves with experience E.

---

## 5. Types of Machine Learning Problems

### 5.1 Classification Problems

* Output belongs to a **finite set of classes**
* Examples:

  * spam vs not spam
  * disease vs healthy
  * fraud vs legitimate

Output:

* class label
* or class probabilities

---

### 5.2 Regression Problems

* Output is a **real-valued number**
* Examples:

  * house price prediction
  * temperature forecasting
  * risk scoring

Regression and classification are the **two most common supervised problem types**, as emphasized in Andrew Ng’s lectures.

---

### 5.3 Other Common Problem Types

Beyond regression and classification, real-world ML problems also include:

* **Clustering**: grouping similar examples
* **Dimensionality reduction**: compressing features
* **Anomaly / outlier detection**: finding abnormal patterns
* **Ranking**: ordering items by relevance
* **Recommendation**: predicting preferences

These are usually unsupervised or weakly supervised.

---

## 6. Types of Learning Paradigms

### 6.1 Supervised Learning

* Dataset contains labeled examples `(x, y)`
* Goal: learn a function `f(x) ≈ y`

Used for:

* classification
* regression

---
### 6.3 Semi-Supervised Learning

* Dataset contains a small amount of labeled data and a large amount of unlabeled data
* Goal: learn a function f(x) ≈ y by leveraging structure found in unlabeled data

Key idea:

* Unlabeled data helps shape the representation of the problem, while labeled data anchors it to the task.

Used for:

* image classification with limited annotations
* speech and text tasks where labeling is expensive
* large-scale industrial ML systems

Semi-supervised learning sits between supervised and unsupervised learning and reflects real-world constraints where labels are costly but raw data is abundant.

---
### 6.3 Unsupervised Learning

* Dataset contains **no labels**
* Goal: discover structure in data

Used for:

* clustering
* dimensionality reduction
* anomaly detection

Unsupervised learning is closer to **compression and pattern discovery** than prediction.

---

### 6.4 Reinforcement Learning

* An agent interacts with an environment
* Actions influence future states
* Feedback is delayed via rewards

Goal:

* learn a **policy** that maximizes long-term reward

Used for:

* games
* robotics
* control systems
* resource management

Reinforcement learning differs fundamentally from supervised learning because decisions are **sequential** and **interdependent**.

---

## 7. Final Perspective

Machine learning is not magic, intelligence, or understanding.

It is:

* statistical modeling
* optimization
* generalization under assumptions
#pragma once
#include <gl/glew.h>
#include <vector>

struct VertexBufferelements 
{
	unsigned int count;
	unsigned int type;
	bool normalised;

	static unsigned int GetSizeofType(unsigned int type) {
		switch (type)
		{
		case GL_FLOAT:	return 4;
		case GL_UNSIGNED_INT:  return 2;
		case GL_UNSIGNED_BYTE: return 1;
		}
		return 0;
	}

};


class VertexBufferLayout {
private:

	std::vector<VertexBufferelements> m_elements;
	unsigned int m_stride;

public:
	VertexBufferLayout() :m_stride(0) {
		
	};
	template<typename T>
	void push(unsigned int count) {
		
	}
	template<>
	void push<float>(unsigned int count) {
		m_elements.push_back({ count, GL_FLOAT, GL_FALSE });
		m_stride += count * VertexBufferelements::GetSizeofType(GL_FLOAT);
	}
	template<>
	void push<unsigned char>(unsigned int count) {
		m_elements.push_back({ count, GL_UNSIGNED_BYTE, GL_TRUE });
		m_stride += count * VertexBufferelements::GetSizeofType(GL_UNSIGNED_BYTE);

	}
	template<>
	void push<unsigned int>(unsigned int count) {
		m_elements.push_back({ count, GL_UNSIGNED_INT, GL_FALSE });
		m_stride += count * VertexBufferelements::GetSizeofType(GL_UNSIGNED_INT);
		
	}

	inline const unsigned int getStride() const { return m_stride; }
	inline const std::vector<VertexBufferelements> getElements() const { return m_elements; }

};